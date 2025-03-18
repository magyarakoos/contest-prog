MOD = 10**9 + 7
a, b, n = map(int, input().split())


def is_good(i):
    return all([int(c) == a or int(c) == b for c in str(i)])


good_numbers = []

for i in range(1, max(a, b) * n + 1):
    if is_good(i):
        good_numbers.append(i)

print(len(good_numbers))
