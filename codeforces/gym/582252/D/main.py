from heapq import heappush, heappop

for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    done = [0] * N
    used = set()
    pq = [(0, i, x, x) for i, x in enumerate(a)]
    result = 0
    while len(pq) > 0:
        d, i, x, y = heappop(pq)
        if done[i]:
            continue
        if not y in used:
            used.add(y)
            done[i] = 1
            result += d
            continue
        if x >= y:
            heappush(pq, (d + 1, i, x, y - 1))
        if x <= y:
            heappush(pq, (d + 1, i, x, y + 1))
    print(result)
