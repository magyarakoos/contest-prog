Y, M, D = map(int, input().split())
A = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] if Y % 4 == 0 else [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
B = [31, 30, 30, 31, 30, 31, 31, 30, 30, 31, 30, 31] if Y % 4 == 0 else [31, 30, 30, 31, 30, 30, 31, 30, 30, 31, 30, 31]

for i in range(M - 1):
    D += A[i]
M = 1
for i in range(12):
    if B[i] < D:
        M += 1
        D -= B[i]
    else:
        break

if M == 6 and D == 31:
    print(Y, M, "SZN")
elif M == 12 and D == 31:
    print(Y, M, "VN")
else:
    print(Y, M, D)
