MOD = 10**9 + 7
a, b, n = map(int, input().split())


def is_good(n):
    return all([int(c) in [a, b] for c in str(n)])


def inv(n):
    return pow(n, MOD - 2, MOD)


for i in range(max(a, b) * n + 1):
    if is_good(i):
        print(i)
