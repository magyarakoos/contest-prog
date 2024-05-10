def draw_circle(x0, y0, radius):
    x = radius
    y = 0
    err = 0

    while x >= y:
        print(x0 + x, y0 + y)
        print(x0 + y, y0 + x)
        print(x0 - y, y0 + x)
        print(x0 - x, y0 + y)
        print(x0 - x, y0 - y)
        print(x0 - y, y0 - x)
        print(x0 + y, y0 - x)
        print(x0 + x, y0 - y)

        if err <= 0:
            y += 1
            err += 2*y + 1
        if err > 0:
            x -= 1
            err -= 2*x + 1

draw_circle(0, 0, 2)
