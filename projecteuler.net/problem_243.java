from sympy.ntheory import totient
import math

def ok(d, n, d2, n2):
    return d*n2 < d2*n

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 39, 41, 43, 47, 53]

LIMIT = 1e9

def ok(d, n, d2, n2):
    return d * n2 < d2 * n

mn = float('inf')

def go(ind, n):
    global mn
    if n > LIMIT:
        return
    if ok(totient(n), n - 1, 15499, 94744):
        mn = min(mn, n)
        return
    if ind == len(primes):
        return
    for i in range(1, 4):
        go(ind+1, n*int(math.pow(primes[ind], i)))

go(0, 1)
print(mn)