import math 
from decimal import *
getcontext().prec = 103


ans = 0 
def solve(a):
    tmp = str(Decimal(a).sqrt()*10**102)
    res = 0
    for i in tmp[:-3]:
        res += int(i)
    return res 

for i in range(1, 100):
    ans += solve(i)
i = 1
while i*i < 100:
    ans -= solve(i*i)
    i+=1
print(ans)
