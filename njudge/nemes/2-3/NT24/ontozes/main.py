Q, M = map(int, input().split())
for _ in range(Q):
    A, X, B, Y = map(int, input().split())
    A = (A - 1) * 24 + X
    B = (B - 1) * 24 + Y
    print((B - A) // M)
