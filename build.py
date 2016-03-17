#!/usr/bin/env python

import os
import glob
import platform
import sys
import re
import argparse
import hashlib
import pickle


MD5_DICT = {}
MD5_FILE = ".md5.pkl"

package = "Pmd"
need_prototype = ("nullcommand", "logincommand","forwardcommand","sdkcommand","monitorpmd","chatcommand","gmcommand","pushpmd","lobbypmd",)

name = os.path.abspath(__file__)
path = os.path.dirname(name)
dirname = os.path.basename(path)
gopath = os.getenv("GOPATH")
if gopath == "" or gopath == None:
    gopath = "/Users/whj/mygo"
system = platform.system().lower()
suffix = system == "windows" and "windows.exe" or system

def pickle_wr(mode,obj = None):
    file_name_path = os.path.join(os.path.dirname(__file__),MD5_FILE)
    with open(file_name_path,mode) as pkl_file:
        if mode == "rb":
            return pickle.load(pkl_file)
        else:
            pickle.dump(obj,pkl_file)

def parser_file_md5():

    global MD5_DICT
    file_name_path = os.path.join(os.path.dirname(__file__),MD5_FILE)
    if not os.path.exists(file_name_path):
        for f in glob.glob("*.proto"):
            with open(f,'r') as fp:
                MD5_DICT["%s"%f] = "none"
        pickle_wr('wb',MD5_DICT)
        return;

    MD5_DICT = pickle_wr('rb')
    bNew = False;
    for f in glob.glob("*.proto"):
        if not MD5_DICT.has_key(f):
            with open(f,'r') as fp:
                MD5_DICT["%s"%f] = "none"
                bNew = True
    if bNew:
        pickle_wr('wb',MD5_DICT)

def build_go():
    for f in glob.glob("*.pb.go"):
        print("rm %s" % f)
        os.remove(f)
    for f in glob.glob("*.pb.h"):
        print("rm %s" % f)
        os.remove(f)
    for f in glob.glob("*.pb.cc"):
        print("rm %s" % f)
        os.remove(f)

    if len(sys.argv) == 2 and sys.argv[1] == "clean":
        sys.exit(0)

    dota = "%s/pkg/%s_*/git.code4.in/mobilegameserver/%s.a" % (gopath, system, dirname)
    for f in glob.glob(dota):
        print("rm %s" % f)
        os.remove(f)

    tools = os.path.join(gopath, "src/git.code4.in/mobilegameserver/tools")
    protoc = os.path.join(tools, "protoc-" + suffix)
    protocgengo = os.path.join(tools, "protoc-gen-go-" + suffix)
    for f in glob.glob("*.proto"):
        cmd = "%s --plugin=protoc-gen-go=%s --go_out=. %s" % (protoc, protocgengo, f)
        print(cmd)
        assert(os.system(cmd) == 0)

    for na in glob.glob("*.pb.go"):
        fp = open(na)
        data = fp.read()
        fp.close()
        names = re.findall("^import\s+(%s[0-9]+)" % package, data, re.M)
        if not names:
            continue
        print("[%s] fix proto import: %s" % (" ".join(names), na))
        fp = open(na)
        data = "".join([line for line in fp if not (line.startswith("import") and [name for name in names if name in line])])
        fp.close()
        fp = open(na, "w")
        for name in names:
            data = data.replace(name + ".", "")
        fp.write(data)
        fp.close()

    for f in need_prototype:
        cmd = "python %s %s.pb.go" % (os.path.join(tools, "prototype.py"), f)
        print(cmd)
        assert(os.system(cmd) == 0)

    cmd = "%s %s ." % (os.path.join(tools, "enummap-" + suffix), package)
    print(cmd)
    assert(os.system(cmd) == 0)

    cmd = "gofmt -w -s enummap.pb.go"
    print(cmd)
    assert(os.system(cmd) == 0)

def build_cpp():
    print("cp  Makefile.py Makefile.am")
    os.system("cp Makefile.py Makefile.am")

    for f in glob.glob("*.pb.go"):
        print("rm %s" % f)
        os.remove(f)
    global MD5_DICT
    for f in glob.glob("*.proto"):
        fp =  open(f,'r')
        if MD5_DICT[f] !=  hashlib.md5(fp.read()).hexdigest():
            f = os.path.join(os.path.dirname(f),os.path.splitext(os.path.basename(f))[0]+".pb.go")
            if os.path.exists(f):
                print("rm %s" % f)
                os.remove(f)
            f = os.path.join(os.path.dirname(f),os.path.splitext(os.path.basename(f))[0]+".pb.h")
            if os.path.exists(f):
                print("rm %s" % f)
                os.remove(f)
            f = os.path.join(os.path.dirname(f),os.path.splitext(os.path.basename(f))[0]+".pb.cc")
            if os.path.exists(f):
                print("rm %s" % f)
                os.remove(f)
        fp.close()

    if len(sys.argv) == 2 and sys.argv[1] == "clean":
        sys.exit(0)


    bNew = False
    #tools = os.path.join(gopath, "src/git.code4.in/mobilegameserver/tools")
    #protoc = os.path.join(tools, "protoc-" + suffix + "-2.6.1")
    protoc = os.path.normpath("../3Party/protobuf-2.6.1/src/protoc")
    for f in glob.glob("*.proto"):
        fp = open(f,'r')
        file_md5 = hashlib.md5(fp.read()).hexdigest()
	if MD5_DICT[f] != file_md5:
            	MD5_DICT[f] = file_md5
            	bNew = True
        	cmd = "%s  --cpp_out=. %s  --proto_path=%s   --proto_path=%s" % (protoc, f,".", os.path.normpath("../platcommon/"))
        	print(cmd)
        	assert(os.system(cmd) == 0)

    if bNew:
        pickle_wr('wb',MD5_DICT)
    if system != "windows":
        cmd = "sed -i '/libplatcommon_la_SOURCES/d' Makefile.am"
        assert(os.system(cmd) == 0)
        cmd = "sed -i '$alibplatcommon_la_SOURCES = "
        for f in glob.glob("*.pb.cc"):
             cmd = cmd + " " + f
        cmd = cmd + "' Makefile.am"
        assert(os.system(cmd) == 0)

#build_go()

prog = os.path.basename(os.path.abspath(__file__))
parser = argparse.ArgumentParser(prog="./%s" % prog)
parser.add_argument("-c", "--cpp", action="store_true", dest="cpp", help="init build environment")
parser.add_argument("-g", "--go", action="store_true", dest="go", help="update dependent repos")
parser.add_argument("-u", "--update", action="store_true", dest="update", help="update proto")
parser.add_argument("-i", "--init", action="store_true", dest="init", help="init proto")
opts = parser.parse_args()
if opts.init:
	cmd = "rm -f %s" % MD5_FILE
	print(cmd)
    	os.system(cmd)
parser_file_md5()
if opts.cpp:
    build_cpp()
elif opts.go:
    build_go()
else:
    build_go()
