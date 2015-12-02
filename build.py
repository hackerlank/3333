#!/usr/bin/env python

import os
import glob
import platform
import sys
import re
import argparse


package = "Pmd"
need_prototype = ("nullcommand", "logincommand","forwardcommand","sdkcommand","monitorpmd","chatcommand",)

name = os.path.abspath(__file__)
path = os.path.dirname(name)
dirname = os.path.basename(path)
gopath = os.getenv("GOPATH")
system = platform.system().lower()
suffix = system == "windows" and "windows.exe" or system

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
    for f in glob.glob("*.proto"):
        cmd = "%s  --cpp_out=. %s  --proto_path=%s   --proto_path=%s" % (protoc, f,".","../platcommon/")
        print(cmd)
        assert(os.system(cmd) == 0)
        #cmd = "%s  --cpp_out=. %s  --proto_path=%s   --proto_path=%s" % (protoc, f,".","../platcommon/")
        #print(cmd)
        #assert(os.system(cmd) == 0)

#build_go()

prog = os.path.basename(os.path.abspath(__file__))
parser = argparse.ArgumentParser(prog="./%s" % prog)
parser.add_argument("-c", "--cpp", action="store_true", dest="cpp", help="init build environment")
parser.add_argument("-g", "--go", action="store_true", dest="go", help="update dependent repos")
opts = parser.parse_args()
if opts.cpp:
    build_cpp()
elif opts.go:
    build_go()
else:
    build_go()
