Q, M = map(int, input().split())
for _ in range(Q):
    A, X, B, Y = map(int, input().split())
    print((((B - 1) * 24 + Y) - ((A - 1) * 24 + X) - 1) // M)