Y, M, D = map(int, input().split())
A = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] if Y % 4 == 0 else [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
B = [31, 30, 30, 31, 30, 31, 31, 30, 30, 31, 30, 31] if Y % 4 == 0 else [31, 30, 30, 31, 30, 30, 31, 30, 30, 31, 30, 31]

# if Y % 4 == 0:
#     for i in range(M - 1):
#         D += LDL[i]
#     wm = 1
#     for i in range(12):
#         if WLDL[i] < D:
#             wm += 1
#             D -= WLDL[i]
#         else:
#             break
#     if wm == 6 and D == 31:
#         print(Y, wm, "SZN")
#     elif wm == 12 and D == 31:
#         print(Y, wm, "VN")
#     else:
#         print(Y, wm, D)
# else:
#     for i in range(M - 1):
#         D += DL[i]
#     wm = 1
#     for i in range(12):
#         if WDL[i] < D:
#             wm += 1
#             D -= WDL[i]
#         else:
#             break
#     if wm == 12 and D == 31:
#         print(Y, wm, "VN")
#     else:
#         print(Y, wm, D)
