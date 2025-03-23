N, MAXN = int(input()), 10**2 + 1

m = [[] for _ in range(MAXN)]
s = [1] * MAXN
for i in range(2, MAXN):
    for j in range(i, MAXN * s[i], i):
        s[j] = 0
        m[j].append(i)

for a in map(int, input().split()):
    print(a)
