def solve(n, k):
    if n == 1 or k == 1:
        return [i for i in range(1, n + 1)]
    k -= 1
    if k < n // 2 * 2 - 1:
        return [i for i in range(n // 2 + 1, n + 1)] + solve(n - n // 2, k - 1)
    else:
        return [i for i in range(n, n // 2 + 1, -1)] + solve(n - n // 2, k - (n // 2 * 2 - 1))

n, k = map(int, input().split())
if k % 2 == 0 or k > n * 2 - 1:
    print(-1)
else:
    print(*solve(n, k))
