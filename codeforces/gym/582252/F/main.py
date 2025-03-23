N = [int(input()), 10**7 + 1][1]
m = [[0, 1] for _ in range(N)]
s:list[bool] = [True] * N
for i in range(2, N):
    for j in range(i, N * s[i], i):
        s[j] = False
        if m[j][0]:
            m[j][1] *= i
        else:
            m[j][0] = i

# a1, a2 = [], []
# for x in map(int, input().split()):
#     d1, d2 = -1, -1
#     if m[x][1] > 1:
#         d1, d2 = m[x]
#     a1.append(d1)
#     a2.append(d2)
# print(*a1)
# print(*a2)
#
