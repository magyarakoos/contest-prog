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


for _ in range(n):
    l = f.readline().strip()
    # if len(l) >= 4:
    #     a.append(["".join(seq) for seq in combinations(l, 4)])
    # else:
    #     a.append([l])

print(a)

# f = open("output.txt", 'w')

