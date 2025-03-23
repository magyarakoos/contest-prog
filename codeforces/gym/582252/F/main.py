N, MAXN = int(input()), 10**2 + 1

m, d = {}, {}
for i, x in enumerate(list(map(int, input().split()))):
    m[x].append(i)
print(m)
print(d)

s = [1] * MAXN
for i in range(2, MAXN):
    for j in range(i * 2, MAXN * s[i], i):
        s[j] = 0
print(s)
