from sympy.solvers.diophantine.diophantine import diop_DN

mx = 1
ans = 1
for D in range(2, 1001):
    tmp = diop_DN(D, 1)
    if tmp[0][0] > mx:
        mx = tmp[0][0]
        ans = D
print(ans)
