import math 

def exponential_mod(n, p, mod):
	if p == 0:
		return 1
	if p%2 != 0:
		return (exponential_mod(n, p-1, mod)*n)%mod
	tmp = exponential_mod(n, p//2, mod)%mod 
	return (tmp*tmp)%mod 

def get_primes(n):
	primes = [True]*(n+1)
	primes[0] = False
	primes[1] = False
	i = 2 
	while i*i <= n:
		if primes[i]:
			j = i*i 
			while j <= n:
				primes[j] = False
				j+=i 
		i+=1
	return primes

p = get_primes(1000000)
n = 1
for i in range(2, 1000000):
	if p[i]:
		r = (exponential_mod(i-1, n, i*i)+exponential_mod(i+1, n, i*i))%(i*i)
		if r > 1e10:
			print(n)
			break
		n += 1
