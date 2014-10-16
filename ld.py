#!/usr/bin/env python

t =int(raw_input())
while t > 0:
    s = raw_input()
    a ,b = s.split()
    k = int(a)**int(b)
    print k%10
    t = t-1
