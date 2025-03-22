for _ in range(int(input())):
    N = int(input())
    a = [0] * N
    for x in input().split():
        a[int(x) - 1] += 1

    dp = [[10**9] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if j + 1 + (i > 0) < a[i]:
                continue
            for k in range(j - a[i] + 1, j + 1):
                dp[i][j] += abs(k - i)
            if i > 0:
                dp[i][j] += min(dp[i - 1][:j - a[i] + 1])
    print(dp)
