from itertools import combinations
fin = open("input.txt")
out = open("output.txt", "w")

n = int(fin.readline())
vis = []
g = [[] for _ in range(n)]
pairs = {}

def combs(s):
    ans = []
    for i in range(1, 5):
        ans.extend(["".join(seq) for seq in combinations(s, i)])
    return ans

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
    line = fin.readline().strip()
    g[i] = combs(line) if len(line) >= 4 else [line]
    vis = [0] * n
    if not dfs(i):
        out.write("-1\n")
        exit(0)

out.writelines([s + "\n" for _, s in sorted([(i, j) for j, i in pairs.items()])])

