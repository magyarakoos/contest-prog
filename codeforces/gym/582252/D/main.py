from heapq import heappush, heappop

for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    used, done = [0] * N, [0] * N
    pq = [(0, i, x, x) for i, x in enumerate(a)]
    result = 0
    while len(pq) > 0:
        d, ai, pi, cp = heappop(pq)
        if done[ai]:
            continue
        if not used[j]:
            used[j] = 1
            done[i] = 1
            result += d
            continue
        if i == j:
