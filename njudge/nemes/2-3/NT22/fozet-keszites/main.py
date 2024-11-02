def gcd(a, b):
    while b:
        a, b = b, a % b
    return abs(a)

R = set()
for i in range(1, 501):
    for j in range(1, 501):
        R.add((i // gcd(i, j), j // gcd(i, j)))

print(R)

# T = int(input())
# for _ in range(T):
#     A, B = map(int, input().split())
