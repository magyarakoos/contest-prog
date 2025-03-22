for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    result = 0
    dp = [[0] * (N + 1) for _ in range(N + 1)]
    print(dp)
