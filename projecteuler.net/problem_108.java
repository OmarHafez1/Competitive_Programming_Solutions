import math
from math import prod
from sympy import factorint
def A018892(n): return prod((a<<1)+1 for a in factorint(n).values())+1>>1 

i = 1
N = int(input())
x = 1

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]
mn = float('inf')

def go(ind, n):
    global mn
    if ind >= len(primes) or n >= 1e16:
        return 0
    tmp = A018892(n)
    if tmp > N:
        mn = min(mn, n)
        return 0
    for i in range(1, 4):
        go(ind+1, n*int(math.pow(primes[ind], i)))

go(0, 1)
print(mn)
