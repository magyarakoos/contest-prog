MOD = 10**9 + 7
a, b, n = map(int, input().split())

fact = [1]
for i in range(100):
    fact.append(fact[-1] * (i + 1) % MOD)


def is_good(n):
    return all([int(c) in [a, b] for c in str(n)])


def choose(n, k):
    return fact[n] * pow(fact[k] * fact[n - k] % MOD, MOD - 2, MOD) % MOD


for i in range(max(a, b) * n + 1):
    if is_good(i):
        print(i)
