MOD = 10**9 + 7
a, b, n = map(int, input().split())
good_numbers = []
for i in range(1, max(a, b) * n + 1):
    if is_good(i):
        good_numbers.append(i)
