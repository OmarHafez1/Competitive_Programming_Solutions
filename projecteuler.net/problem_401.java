from math import isqrt
def f(n): return n*(n+1)*(2*n+1)//6
def a(n):
    s = isqrt(n)
    return sum(f(n//k) + k*k*(n//k) for k in range(1, s+1)) - s*f(s)
res = a(1000000000000000)%1000000000
print(res)