import math 
from decimal import *
getcontext().prec = 103

def sm(n):
    res = 0
    while n > 0:
        res += n%10 
        n //=10
    return res

st = [0]

for i in range(2, 100):
    for j in range(1, 10):
        n = i**j
        if n >= 10:
            if sm(n) == i:
                st.append(n)
st.sort()
print(st[30])