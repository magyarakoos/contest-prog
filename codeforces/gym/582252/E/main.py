def read():
    n = int(input())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(complex(x, y))
    return a

def turn(A, B, C):
    return (C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x)

def hull(ptS):

    pass

a, b = read(), read()
print("YES" if list(set(a + b)) == a + b and hull(a + b) == a else "NO")
