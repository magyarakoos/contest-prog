T = int(input())
for _ in range(T):
    N = int(input())
    P = list(map(int, input().split()))
    S = [25, 18, 15, 12, 10, 8, 6, 4, 2, 1, 0]
    score = sum([S[min(x - 1, 10)] for x in P])
    print(score)
