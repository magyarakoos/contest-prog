MOD = 10**9 + 7
a, b, n = map(int, input().split())


def is_good(i):
    return all([c == a + '0' or c == b + '0' for c in str(i)])


good_numbers = []

for i in range(1, max(a, b) * n + 1):
    if is_good(i):
        good_numbers.append(i)

print(*good_numbers)
