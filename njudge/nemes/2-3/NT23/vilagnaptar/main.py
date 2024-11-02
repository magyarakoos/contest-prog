Y, M, D = map(int, input().split())
A = [31, 28 + (Y % 4 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
B = [31, 30, 30, 31, 30, 30 + (Y % 4 == 0), 31, 30, 30, 31, 30, 31]
for i in range(M - 1):
    D += A[i]
M = 1
for i in range(12):
    if B[i] < D:
        M += 1
        D -= B[i]
    else:
        break
print(Y, M, "SZN" if M == 6 and D == 31 else "VN" if M == 12 and D == 31 else D)
