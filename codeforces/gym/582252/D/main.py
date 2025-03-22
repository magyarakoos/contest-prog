for _ in range(int(input())):
    N = int(input())
    a = [0] * N
    for x in input().split():
        a[int(x) - 1] += 1

    print(a)
    dp = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if j - a[i] + (i == 0) >= 0:
                for k in range(j - a[i] + 1, j + 1):
                    dp[i][j] += abs(k - i)
                if i > 0:
                    dp[i][j] += min(dp[i - 1][:j - a[i] + 1])
            else:
                dp[i][j] = 10**9
        print(dp[i])
