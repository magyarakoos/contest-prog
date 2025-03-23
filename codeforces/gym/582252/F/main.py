from array import array

N = [int(input()), 10**7 + 1][1]
s, ma, mb = array('I', [1] * N), array('I', [0] * N), array('I', [1] * N)
for i in range(2, N):
    for j in range(i, N * s[i], i):
        s[j] = False
        if ma[j]:
            mb[j] *= i
        else:
            ma[j] = i

a1, a2 = [], []
for x in map(int, input().split()):
    d1, d2 = -1, -1
    if mb[x] > 1:
        d1, d2 = ma[x], mb[x]
    a1.append(d1)
    a2.append(d2)
print(*a1)
print(*a2)

