!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
    
    
def main(path):
    """
    Function which prints counts of spaces, tabs and lines in a file.
    :arg path: Path of the text file to parse
    :return: True if the file exits or False.
    """
    if os.path.exists(path):
        fd = open(path)
        i = 0
        
        
        while i < 3:

            ch = fd.readline()
            
            s = ''.join(x for x in ch if x.isdigit())
            k = int(s) / 1024
            print "%d MB" %k
            
            
            
            i = i+1
	
    

if __name__ == '__main__':
    if len(sys.argv) > 1:
	main(sys.argv[1])
    else:
	sys.exit(-1)
    sys.exit(0)






