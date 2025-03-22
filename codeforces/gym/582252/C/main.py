from itertools import combinations
f = open("input.txt")

n = int(f.readline())
a = []
vis = [0] * n
g = [[] for _ in range(n)]

def dfs(i):
    if vis[i]:
        return 0
    vis[i] = 1


for i in range(n):
    l = f.readline().strip()
    g[i] = ["".join(seq) for seq in combinations(l, 4)] if len(l) >= 4 else [l]


print(a)

# f = open("output.txt", 'w')

