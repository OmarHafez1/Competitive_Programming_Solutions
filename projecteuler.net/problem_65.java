import math
from fractions import Fraction

arr = [1, 2]
lst = 4
while len(arr) < 100:
    arr += [1, 1, lst]
    lst += 2

def solve(cnt, f, n):
    if cnt >= n-1:
        return f
    return f+Fraction(1, arr[cnt]+solve(cnt+1, 0, n))

num = solve(0, 2, 100).numerator
ans = 0
while num > 0:
    ans += num%10
    num //=10
print(ans)