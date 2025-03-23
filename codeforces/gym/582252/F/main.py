from math import gcd

_, MAXN = int(input()), 10**2 + 1

m = [[] for _ in range(MAXN)]
s = [1] * MAXN
for i in range(2, MAXN):
    for j in range(i, MAXN * s[i], i):
        s[j] = 0
        m[j].append(i)

a1, a2 = [], []
for x in map(int, input().split()):
    for d in m[x]:
        for e in m[x]:
            if not d == e and gcd(d + e, x) == 1:

