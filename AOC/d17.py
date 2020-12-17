from functools import wraps
from datetime import datetime
from itertools import product
import operator

total_time = []


def measure_time(func):
    @wraps(func)
    def _func(*args, **kwargs):
        start = datetime.now()
        result = func(*args, **kwargs)
        end = datetime.now()
        total_time.append((end - start).total_seconds())
        return result

    return _func


@measure_time
def parse(raw_data):
    grid = set()
    z = 0
    lines = raw_data.splitlines()
    for y,line in enumerate(lines):
        for x,c in enumerate(line):
            if c == "#":
                grid.add((x,y,z))
    # return size of grid and set of active points
    return ([[-1,len(lines[0])+1], [-1,len(lines)+1], [-1,1]], grid)


def active_neighbors_nD(point, grid):
    count = 0
    for p in product(*(range(x-1, x+2) for x in point)):
        if p in grid and p != point:
            count += 1
    return count


def conway_step_nD(dims, grid):
    active = set()
    inactive = set()
    for point in product(*(range(*d) for d in dims)):
        neighs = active_neighbors_nD(point, grid)
        if point in grid:
            if not (neighs == 2 or neighs == 3):
                # use that the grid is symmetric in all dimension except x and y
                inactive = inactive.union(reflections_xy(point))
        else:
            if neighs == 3:
                active = active.union(reflections_xy(point))
    assert active.intersection(inactive) == set()
    grid = grid.union(active)
    grid = grid.difference(inactive)
    # update grid dimensions
    dims[0][0] -= 1
    dims[0][1] += 1
    dims[1][0] -= 1
    dims[1][1] += 1
    for i in range(2, len(dims)):
        dims[i][0] -= 1

    return (dims, grid)


def reflections_xy(point):
    x, y, *rest = point
    mirrors = product(*[(1,-1) for _ in range(len(rest))])
    return set((x,y,*tuple(map(operator.mul, mirror, rest))) for mirror in mirrors)
    


# PART 1
@measure_time
def solve1(data):
    dims, grid = data
    for _ in range(6):
        dims, grid = conway_step_nD(dims, grid)
    return len(grid)


# PART 2
@measure_time
def solve2(data):
    dims, grid = data
    grid = set([(x,y,z,0) for x,y,z in grid])
    dims = [*dims, [-1,1]]
    for _ in range(6):
        dims, grid = conway_step_nD(dims, grid)
    return len(grid)


if __name__ == "__main__":
    import sys

    data = parse(open("input").read().strip())
    print("Part 1: {}".format(solve1(data)))
    print("Part 2: {}".format(solve2(data)))

    print("total time: {}s".format(sum(total_time)))