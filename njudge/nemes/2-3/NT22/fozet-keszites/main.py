def gcd(a, b):
    while b:
        a, b = b, a % b
    return abs(a)

dp = [[0] * 501 for _ in range(501)]
for i in range(25):
    for j in range(25):
        if gcd(i, j) != 1:
            continue
        for k in range(i, 501):
            for l in range(j, 501):
                dp[k][l] = min(dp[k][l], dp[k - i][l - j] + 1)

T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    print(dp[A][B])
