def solve(n, k):
    print(n, k)
    k -= 1
    if n == 1:
        return [1]
    elif k < n // 2 * 2 - 1:
        return [i for i in range(1, n // 2 + 1)] + [x + n // 2 for x in solve(n - n // 2, k)]
    else:
        return [i for i in range(n // 2, 0, -1)] + [x + n // 2 for x in solve(n - n // 2, k - (n // 2 * 2 - 1))]
print(*solve(*map(int, input().split())))
