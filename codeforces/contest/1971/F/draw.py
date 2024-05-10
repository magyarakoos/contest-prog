import math

def count_lattice_points(r):
    count = 0
    for x in range(0, r+1):
        y = math.sqrt(r**2 - x**2)
        count += math.floor(y)
    return 4*count + 1  # multiply by 4 and add 1 for the origin

r = 2  # example input
print(count_lattice_points(r))
