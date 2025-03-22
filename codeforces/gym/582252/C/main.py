from itertools import combinations
in = open("input.txt")
out = open("output.txt", "w")

n = int(in.readline())
vis = []
g = [[] for _ in range(n)]
pairs = {}

def dfs(i):
    if vis[i]:
        return False
    vis[i] = 1
    for j in g[i]:
        if not j in pairs or dfs(pairs[j]):
            pairs[j] = i
            return True
    return False

for i in range(n):
    l = in.readline().strip()
    g[i] = ["".join(seq) for seq in combinations(l, 4)] if len(l) >= 4 else [l]
    vis = [0] * n
    if not dfs(i):
        print(-1)
        exit(0)

for i, s in sorted([(i, j) for j, i in pairs.items()]):
    print(s)



