for _ in range(int(input())):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    print(a, b)
