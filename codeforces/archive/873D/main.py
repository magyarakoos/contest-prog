def solve(n, k):
    if n == 1 or k == 1:
        return [i for i in range(1, n + 1)]
    if k <= n // 2 * 2 - 1:
        return [i for i in range(1, n // 2 + 1)] + [x + n // 2 for x in solve(n - n // 2, k)]
    else:
        return [i for i in range(n // 2, 0, -1)] + [x + n // 2 for x in solve(n - n // 2, k - n // 2 * 2 - 1)]


n, k = map(int, input().split())
print(solve(n, k))
