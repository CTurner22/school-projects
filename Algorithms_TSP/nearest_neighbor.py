from points import find_distance


def nearest_neighbor(points):

    # start at first point and initialize variables
    previous_point = points[0]
    path = [previous_point]
    points.remove(previous_point)
    total_distance = 0.0

    while len(points) > 0:
        # find next closest point
        distance, next_point = find_closest(previous_point, points)

        # add to distance traveled and remove point from unvisited
        total_distance += distance
        path.append(next_point)
        points.remove(next_point)

        # move to next point
        previous_point = next_point

    # return to starting point
    total_distance += find_distance(previous_point, path[0])
    path.append(path[0])

    return total_distance, path


def find_closest(start, points):

    next_point = points[0]
    closest_distance = find_distance(start, next_point)

    for p in points:
        distance = find_distance(start, p)
        if distance < closest_distance:
            closest_distance = distance
            next_point = p

    return closest_distance, next_point

