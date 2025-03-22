for _ in range(int(input())):
    N = int(input())
    a = [0] * N
    for x in input().split():
        a[int(x) - 1] += 1

    dp = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if j + 1 < a[i]:
                dp[i][j] = 10**9
                continue
