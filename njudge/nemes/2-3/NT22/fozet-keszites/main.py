def gcd(a, b):
    while b:
        a, b = b, a % b
    return abs(a)

dp = [[0] * 501 for _ in range(501)]

T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    print(dp[A][B])
