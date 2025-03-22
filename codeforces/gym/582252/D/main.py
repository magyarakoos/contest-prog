from heapq import heappush, heappop

for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    used, done = [0] * N, [0] * N
    pq = [(i, i) for i in range(N)]
    result = 0
    while len(pq) > 0:
        i, j = heappop(pq)
        d = abs(i - j)
        if not used[j]:
            used[j] = 1
            result += d
            continue
