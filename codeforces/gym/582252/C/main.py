from itertools import combinations
f = open("input.txt")

n = int(f.readline())
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
    l = f.readline().strip()
    g[i] = ["".join(seq) for seq in combinations(l, 4)] if len(l) >= 4 else [l]
    vis = [0] * n
    if not dfs(i):
        print(-1)
        exit(0)

ans = [(i, j) for j, i in pairs.items()]
print(ans)

print(ans)

# f = open("output.txt", 'w')

