def solve(n, k):
    a = []
    for i in range(n // 2, 0, -1):
        a.append(i)
    return a

n, k = map(int, input().split())
print(solve(n, k))
