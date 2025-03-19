MOD, fact, ans = 10**9 + 7, [1], 0
a, b, n = map(int, input().split())
for i in range(n):
    fact.append(fact[-1] * (i + 1) % MOD)

def choose(n, k):
    return fact[n] * pow(fact[k] * fact[n - k] % MOD, MOD - 2, MOD) % MOD

for i in range(max(a, b) * n + 1):
    if all([int(c) in [a, b] for c in str(i)]):
        for j in range(0, n + 1):
            if j * a + (n - j) * b == i:
                ans += choose(n, j)
                ans %= MOD
print(ans)
