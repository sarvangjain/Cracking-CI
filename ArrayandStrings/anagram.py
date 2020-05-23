#!/bin/python3

import math
import os
import random
import re
import sys

def anagram(s1,s2):
	for ch in s1:
		if s1.count(ch) != s2.count(ch):
			return False

	return True

if __name__ == '__main__':
	s1 = input()
	s2 = input()
	ans = anagram(s1,s2)
	print(ans)
