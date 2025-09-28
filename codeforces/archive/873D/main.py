def solve(n, k):
    a = []
    for i in range(n // 2, 0, -1):
        a.append(i)
    # for i in solve(n - n // 2, k - n // 2 - 1):
    #     a.append(i + n // 2)
    return a

n, k = map(int, input().split())
print(solve(n, k))
