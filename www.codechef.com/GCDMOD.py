import math

t = int(input())

MOD = 1000000007

def exponential_mod(n, p, mod) :
	if p == 0 :
		return 1
	if p%2 != 0 :
		return (exponential_mod(n, p-1, mod)*n)%mod
	tmp = exponential_mod(n, p//2, mod)%mod
	return (tmp*tmp)%mod

def swap(a, b):
	tmp = a
	a = b
	b = tmp

while t > 0:
	t -= 1
	a,b,n=list(map(int,input().split()))
	if a == b:
		print((exponential_mod(a, n, MOD)+exponential_mod(b, n, MOD))%MOD)
	else:
		if b > a:
			swap(a, b)
		print(int(math.gcd((exponential_mod(a, n, a-b)+exponential_mod(b, n, a-b))%(a-b), a-b)))