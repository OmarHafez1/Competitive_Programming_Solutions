import math

n,m,t = map(int,input().split())

ans = 0
for i in range(4, n+1):
	j = t-i
	if j > m or j < 1:
		continue
	ans += math.comb(n, i) * math.comb(m, j)
print(ans)

