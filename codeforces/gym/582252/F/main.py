from collections import defaultdict


N, MAXN = int(input()), 10**2 + 1

m = [[[] for _ in range(MAXN)] for _ in range(2)]
for i, x in enumerate(list(map(int, input().split()))):
    m[0][x].append(i)
print(m)

s = [1] * MAXN
for i in range(2, MAXN):
    if s[i]:

    for j in range(i * 2, MAXN, i):
        s[j] = 0
            m[1][j]
    
print(s)
