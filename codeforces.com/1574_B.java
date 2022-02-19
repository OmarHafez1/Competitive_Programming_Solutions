import math
t = int(input())
for _ in range(t):
	a, b, c, m = map(int, input().split())
	a, b, c = sorted([a, b, c])
	print("YES" if c-1-a-b <= m <= a+b+c-3 else "NO")