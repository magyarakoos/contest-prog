from itertools import combinations
f = open("input.txt")

n = int(f.readline())
a = []
for l in f.readlines():
    a.append(["".join(seq) for seq in combinations(l[-1::], 4)])

print(a)

# f = open("output.txt", 'w')

