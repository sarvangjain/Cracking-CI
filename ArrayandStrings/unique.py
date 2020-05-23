#!/bin/python3

import math
import os
import random
import re
import sys

def unique(s):
	for ch in s:
		if s.count(ch) > 1:
			return False
	return True
	
if __name__ == '__main__':
	s = input()
	ans = unique(s)
	print(ans)	