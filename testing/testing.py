#!/usr/bin/env python
import sys

def div(n,d):
    return n/d -1
def validate_user_input():
    try:
        n ,d = int(sys.argv[1]), int(sys.argv[2])
        return n, d
    except ValueError:
        print "Enter only integer arguments!"

if __name__ == '__main__':
    validated_values = validate_user_input()
    if validated_values:
        n, d = validated_values
        print div(n, d)
