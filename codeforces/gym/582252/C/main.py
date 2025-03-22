from itertools import combinations
f = open("input.txt")

n = int(f.readline())
a = []
for _ in range(n):
    a.append(["".join(seq) for seq in combinations(f.read(), 4)])

print(a)

# f = open("output.txt", 'w')

