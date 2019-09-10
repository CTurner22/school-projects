import math
import random


class Point:
    """
    class used to represent points on x,y axis
    """
    def __init__(self, x, y,):
        self.x = x
        self.y = y

    def __str__(self):
        return str(self.x) + ' ' + str(self.y)


def find_distance(start, finish):
    """
    Finds the distance between two given points

    :param start:
    :param finish:
    :return:
    """
    return math.sqrt(float((start.x - finish.x)**2 + (start.y-finish.y)**2))


def get_points_from_file():
    """
    Reads in input points from file input.txt

    :return:
    """
    input_file = open('input.txt', 'r')
    size = int(input_file.readline())

    points = []
    for i in range(size):
        x, y = input_file.readline().strip('\n').split(' ')
        points.append(Point(int(x), int(y)))

    return points


def get_random_points():
    """
    Randomly generates input points between +-(100,100)

    :return:
    """
    print('\nHow many points would you like to generate?')
    n = int(input('n = '))
    points = []

    for i in range(n):
        points.append(Point(random.randint(-100, 100), random.randint(-100, 100)))

    return points


def format_results(distance, path, clocked_at):
    """
    Formats and outputs results.

    :param distance:
    :param path:
    :param clocked_at:
    :return:
    """
    avg_time = 0
    for t in clocked_at:
        avg_time += (t / len(clocked_at))

    print('distance: {0:.3f}'.format(distance))
    for p in path:
        print(p)

    print('\ntime: {} seconds'.format(clocked_at))
    print('\nAvg time: {} seconds'.format(avg_time))