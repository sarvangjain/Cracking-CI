#!/bin/python3

import math
import os
import random
import re
import sys

def rot(mat,n):
	arr = [1]*n
	for i in range(n):
		l= mat[i]
		arr.append(l)
		for j in range(n):
			if mat[i][j] == 0:
				for k in range(n):
					arr[k][j] = 0
				l = [0]*n
			

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