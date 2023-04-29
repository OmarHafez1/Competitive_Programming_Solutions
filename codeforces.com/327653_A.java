import math

w = input().split(' ');
n = int(w[0])
m = int(w[1])

lst = False

for i in range(0, n):
    res = ""
    if i%2 == 0:
        res = '#'*m
    else :
        if lst:
            res = '#'+'.'*(m-1)
        else :
            res = '.'*(m-1)+'#'
        lst = not lst
    print(res)