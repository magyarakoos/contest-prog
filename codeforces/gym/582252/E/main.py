def read():
    n = int(input())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(complex(x, y))
    return a

def hull():
    pass

A, B = read(), read()

print(hull())
