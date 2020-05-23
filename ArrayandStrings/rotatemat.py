#!/bin/python3

import math
import os
import random
import re
import sys

def rot(mat,n):
	arr = []
	for i in range(n):
		l = []
		for j in range(n):
			l.append(mat[n-j-1][i])
		arr.append(l)

	return arr

if __name__ == '__main__':
	n = int(input())
	mat = []
	for k in range(n):
		a = list(map(int,input().rstrip().split()))
		mat.append(a)
	ans = rot(mat,n)
	print()
	for i in range(n):
		print(*ans[i],sep = ' ')