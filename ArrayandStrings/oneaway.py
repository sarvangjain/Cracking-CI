#!/bin/python3

import math
import os
import random
import re
import sys

def edits(s1,s2):
	t = 0
	for ch in s1:
		t += s1.count(ch) - s2.count(ch)

	if t < 2:
		return True
	else:
		return False

if __name__ == '__main__':
	s1 = input()
	s2 = input()
	ans = edits(s1,s2)
	print(ans)