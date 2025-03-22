from heapq import heappush, heappop

for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    used = [0] * N
    pq = [(i, i) for i in range(N)]
    while len(pq) > 0:
        i, j = heappop(pq)
        d = abs(i - j)
