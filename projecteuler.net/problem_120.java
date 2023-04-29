import math 

def exponential_mod(n, p, mod):
	if p == 0:
		return 1
	if p%2 != 0:
		return (exponential_mod(n, p-1, mod)*n)%mod
	tmp = exponential_mod(n, p//2, mod)%mod 
	return (tmp*tmp)%mod 

ans = 0
for a in range(3, 1001):
	mx = 0
	for n in range(1, 2000):
		r = (exponential_mod(a-1, n, a*a)+exponential_mod(a+1, n, a*a))%(a*a)
		mx = max(mx, r)
	ans += mx
print(ans)
