import math
from sortedcontainers import SortedDict

def get_primes(n) :
    primes = [True]*(n+1)
    primes[0] = False
    primes[1] = False
    i = 2
    while i*i <= n:
        if primes[i]:
            j = i*i 
            while j <= n:
                primes[j] = False
                j+=i
        i+=1
    return primes

def ok(p, q):
    tmp = p*math.log10(q) + q*math.log10(p)
    return tmp <= MAX

tmp = input().split()
N = int(tmp[0])
M = int(tmp[1])

MAX = math.log10(N)*M

tmp = get_primes(15704507)

primes = []
for i in range(2, len(tmp)):
    if tmp[i]:
        primes.append(i) 
ans = 0 
lst = 1 
mp = SortedDict({})
for i in range(0, len(primes)):
    mp[primes[i]] = lst
    lst += 1
for i in range(0, len(primes)):
    left = 0
    right = i
    mid = 0
    while left < right:
        mid = (left+right)//2
        if ok(primes[mid], primes[i]):
            left = mid+1
        else:
            right = mid 
    if mid == i:
        mid-=1 
    if not ok(primes[mid], primes[i]):
        mid-=1 
    if mid >= 0:
        ans += mp[primes[mid]]
print(ans)
