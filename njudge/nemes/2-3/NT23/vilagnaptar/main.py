DL   = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
LDL  = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
WDL  = [31, 30, 30, 31, 30, 30, 31, 30, 30, 31, 30, 31]
WLDL = [31, 30, 30, 31, 30, 31, 31, 30, 30, 31, 30, 31]

Y, M, D = map(int, input().split())
if Y % 4 == 0:
    pass
else:
    for i in range(M - 1):
        D += DL[i]
    wm = 1
    for i in range(12):
        if WDL[i] < D:
            wm += 1
            D -= WDL[i]
        else:
            break
    print(Y, wm, D)

