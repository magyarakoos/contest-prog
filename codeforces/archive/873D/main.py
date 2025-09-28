def solve(n, k):
    if n <= 0 or k <= 0:
        return []
    a = []
    for i in range(n // 2, 0, -1):
        a.append(i)
    for i in solve(n - n // 2, k - n // 2 * 2):
        a.append(i + n // 2)
    print(n, k, a)
    return a

n, k = map(int, input().split())
print(solve(n, k))
