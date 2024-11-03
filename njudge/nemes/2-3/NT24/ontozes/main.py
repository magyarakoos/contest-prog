Q, M = map(int, input().split())
for _ in range(Q):
    A, B, X, Y = map(int, input().split())
    A = (A - 1) * 24 + X
    B = (B - 1) * 24 + Y
    print(A, B)
    print((B - A + M - 1) // M)
