N = [int(input()), 10**7 + 1][1]
s, ma, mb = [1] * N, [0] * N, [1] * N
for i in range(2, N):
    for j in range(i, N * s[i], i):
        s[j] = False
        if ma[j]:
            mb[j] *= i
        else:
            ma[j] = i

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
