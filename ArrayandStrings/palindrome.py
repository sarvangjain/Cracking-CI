#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
	s = ''.join(input().split())
	c = 0
	for ch in s:
		if s.count(ch) % 2 == 0:
			continue
		else:
			c += 1

	if c > 1:
		print(False)
	else:
		print(True)