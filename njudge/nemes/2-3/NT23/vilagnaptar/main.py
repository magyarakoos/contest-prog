DL = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
LDL = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
WDL = [31, 30, 30, 31, 30, 30, 31, 30, 30, 31, 30, 30, 1]

Y, M, D = map(int, input().split())
if Y % 4 == 0:
    pass
else:
    pass

print(sum(NDL), sum(LDL), sum(WDL))
