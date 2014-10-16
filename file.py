!/usr/bin/env python

import sys
import os

name = sys.argv[1]
if not os.path.exists(name):
    print "File does not exist."
else:

    fobj = open(name,"r")
    for i in fobj:
        print i
    fobj.close()



