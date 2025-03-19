from itertools import combinations

n = int(input())
a = []
for _ in range(n):
    a.append(["".join(seq) for seq in combinations(input(), 4)])
print(a)
