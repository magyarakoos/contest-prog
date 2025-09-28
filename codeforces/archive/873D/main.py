def solve(n, k):
    if n == 1:
        return [1]
    a = []
    for i in range(n // 2, 0, -1):
        a.append(i)
    print (n // 2, n // 2 * 2 - 1, a)
    for i in solve(n - n // 2, k - n // 2 - 1):
        a.append(i + n // 2)
    print(n, k, a)
    return a

n, k = map(int, input().split())
print(solve(n, k))
