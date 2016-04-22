#!/usr/bin/env python
#coding:utf-8
import glob, os

def modify_makefile(makefile):
    sources = ""
    for f in glob.glob("*.cpp"):
        sources = ("%s %s\/%s") % (sources, "gbuffer", f)
    cmd = ("sed -i 's/GBUFFER_SRC =.*/GBUFFER_SRC =%s/g' %s") % (sources, makefile)
    assert(os.system(cmd) == 0)

if __name__ == "__main__":
    modify_makefile("../Makefile.am")
