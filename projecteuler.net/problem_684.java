import math

MOD = 1000000007

def exponential_mod(n, p):
	if p == 0:
		return 1
	if p%2 != 0:
		return (exponential_mod(n, p-1)*n)%MOD 
	tmp = exponential_mod(n, p//2)%MOD 
	return (tmp*tmp)%MOD

def S(N):
	n = N//9
	r = N%9
	return ((r+6+(r*(r+1))//2)*exponential_mod(10, n)-(r+9*n+6))%MOD

a = 0 
b = 1
ans = 0 

for i in range(1, 90):
	c = a+b 
	ans += S(c)
	a = b 
	b = c 
print(ans%MOD)

