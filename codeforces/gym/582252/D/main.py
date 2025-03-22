from heapq import heappush, heappop

for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    used = [0] * N
    pq = [(i, i, 0) for i in range(N)]
    print(pq)
