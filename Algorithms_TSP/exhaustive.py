# from itertools import permutations
from points import Point, find_distance


def exhaustive_tsp(points):

    # start at first point
    start = points.pop(0)

    # find all possible paths, can just import permutations library, but
    # wrote function in order to evaluate algorithm better
    all_possible_paths = permutations(points)

    # add start point back to start and finish of each path and
    # iterate through to find the shortest distance
    shortest_path = [start] + all_possible_paths.pop() + [start]
    shortest_distance = find_path_distance(shortest_path)

    for path in all_possible_paths:
        path = [start] + path + [start]
        distance = find_path_distance(path)

        if distance < shortest_distance:
            shortest_distance = distance
            shortest_path = path

    return shortest_distance, shortest_path


def permutations(starting_list):
    # Base Case
    if len(starting_list) == 0:
        return []

    if len(starting_list) == 1:
        return starting_list

    list_of_permutations = []

    # individually take each point in the starting list and place it in first, then recursively permute the remaining
    for i in range(len(starting_list)):
        n = starting_list[i]

        remaining = starting_list[:i] + starting_list[i+1:]
        for perm in permutations(remaining):
            if isinstance(perm, Point):
                perm = [perm]
            list_of_permutations.append([n] + perm)

    return list_of_permutations


def find_path_distance(path):
    distance = 0.0

    for i in range(len(path) - 1):
        distance += find_distance(path[i], path[i+1])

    return distance

