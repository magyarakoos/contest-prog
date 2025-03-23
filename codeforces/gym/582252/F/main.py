N, MAXN = int(input()), 10**2 + 1
a = list(map(int, input().split()))
s = [1] * MAXN
for i in range(2, MAXN):
    if s[i]:
        for j in range(i * 2, MAXN, i):
            s[j] = 0
print(s)
