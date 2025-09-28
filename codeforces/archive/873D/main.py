def solve(n, k):
    a = []
    for i in range(n // 2, 1, -1):
        a.append(i)
    return a

n, k = map(int, input())
print(solve(n, k))
