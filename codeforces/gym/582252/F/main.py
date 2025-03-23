from math import gcd
from itertools import combinations

N = [int(input()), 10**7 + 1][1]
m = [[] for _ in range(N)]
s = [1] * N
for i in range(2, N):
    for j in range(i, N * s[i], i):
        s[j] = 0
        m[j].append(i)

exit(0)

a1, a2 = [], []
for x in map(int, input().split()):
    a1.append(-1)
    a2.append(-1)
    for d1, d2 in combinations(m[x], 2):
        if gcd(d1 + d2, x) == 1:
            a1[-1] = d1
            a2[-1] = d2
print(*a1)
print(*a2)
