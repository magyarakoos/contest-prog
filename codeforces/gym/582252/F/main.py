from math import gcd
from itertools import combinations

_, MAXN = int(input()), 10**2 + 1

m = [[] for _ in range(MAXN)]
s = [1] * MAXN
for i in range(2, MAXN):
    for j in range(i, MAXN * s[i], i):
        s[j] = 0
        m[j].append(i)

a1, a2 = [], []
for x in map(int, input().split()):
    print(x, combinations(m[x], 2))
