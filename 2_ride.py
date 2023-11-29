"""
ID: 27ckuzm1
PROG: ride
LANG: PYTHON3
"""
from itertools import islice
import string

fin = open('ride.in', 'r')
fout = open('ride.out', 'w')

lines = fin.readlines()

word1 = list(lines[0])
word2 = list(lines[1])

if '\n' in word1:
  word1.remove('\n')


def ltons(n):
  if n.isalpha():
    return string.ascii_uppercase.index(n) + 1
  else:
    return 1


def lton(n):
  tolist = list(map(ltons, n))
  result = 1
  for num in tolist:
    result = result * num
  return result


def issame(x, y):
  if (lton(x) % 47 == lton(y) % 47):
    return "GO"
  else:
    return "STAY"


fout.write(issame(word1, word2) + "\n")
fout.close
