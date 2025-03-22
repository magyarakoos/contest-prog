for _ in range(int(input())):
    N = int(input())
    a = [0] * N
    map(lambda x: a[int(x) - 1] += 1, input().split())
    result = 0
    dp = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            
