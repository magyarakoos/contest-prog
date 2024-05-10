def draw_circle(x0, y0, radius):
    x = radius
    y = 0
    err = 0
    points = set()

    while x >= y:
        points.add((x0 + x, y0 + y))
        points.add((x0 + y, y0 + x))
        points.add((x0 - y, y0 + x))
        points.add((x0 - x, y0 + y))
        points.add((x0 - x, y0 - y))
        points.add((x0 - y, y0 - x))
        points.add((x0 + y, y0 - x))
        points.add((x0 + x, y0 - y))

        if err <= 0:
            y += 1
            err += 2*y + 1
        if err > 0:
            x -= 1
            err -= 2*x + 1

    return len(points)

print(draw_circle(0, 0, 3))
