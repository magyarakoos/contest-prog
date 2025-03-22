def read():
    n = int(input())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(complex(x, y))
    return (n, a)
N, A = read()
M, B = read()

print(N, A)
print(M, B)
