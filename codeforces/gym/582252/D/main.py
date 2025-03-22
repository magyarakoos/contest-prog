for _ in range(int(input())):
    N = int(input())
    a = [0] * N
    b  = [int(x) - 1 for x in input().split()]
    print(a, b)
    result = 0
    dp = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            pass
