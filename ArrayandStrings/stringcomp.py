#!/bin/python3

import math
import os
import random
import re
import sys

def compr(s):
	com = ''
	l = len(s)
	i = 0
	while i < l:
		ch = s[i]
		c = 1
		for j in range(i+1,l):
			if s[j] == ch:
				c+=1
			else:
				break
		com += ch + str(c)
		i += c

	lc = len(com)
	if lc < l:
		return com
	else:
		return s



if __name__ == '__main__':
	s = input()
	ans = compr(s)
	print(ans)