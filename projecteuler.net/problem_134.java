import math

N = 1000004
isPrime = [True] * (N+1)

isPrime[0] = False
isPrime[1] = False

i = 2
while i*i <= N:
	if isPrime[i]:
		j = i*i 
		while j <= N:
			isPrime[j] = False
			j+=i
	i+=1

primes = []

for i in range(5, N+1):
	if isPrime[i]:
		primes.append(i)

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    return x % m

def extended_euclidean_algorithm(a, b):
	k = 0 
	newt = 1 
	r = b 
	newr = a 
	while newr != 0:
		quotient = r//newr
		k, newt = newt, k-quotient*newt
		r, newr = newr, r-quotient*newr
	if k < 0:
		k += b 
	return k

ans = 0

for i in range(0, len(primes)-1):
	p1 = primes[i]
	p2 = primes[i+1]
	w = int(math.pow(10, int(math.log10(p1))+1))

	ans += extended_euclidean_algorithm(w*modinv(p2-p1, p2), p2)*w+p1

print(ans)
