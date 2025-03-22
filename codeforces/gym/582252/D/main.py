from heapq import heappush, heappop

for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    used, done = [0] * N, [0] * N
    pq = [(i, i) for i in range(N)]
    result = 0
    while len(pq) > 0:
        i, j = heappop(pq)
        if done[i]:
            continue
        if not used[j]:
            used[j] = 1
            done[i] = 1
            result += abs(i - j)
            continue
        heappush(pq, (i, j + 1))
        heappush(pq, (i, j - 1))
