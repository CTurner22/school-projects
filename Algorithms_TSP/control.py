from points import get_points_from_file, get_random_points, format_results
from nearest_neighbor import nearest_neighbor
from exhaustive import exhaustive_tsp
import time


def main():
    while True:
        print('Would you like to get input from file or generate randomly?')
        print('1) read from file')
        print('2) randomly generate')
        input_choice = int(input('Enter number: '))

        if input_choice == 1:
            points = get_points_from_file()
        else:
            points = get_random_points()

        print('\nYour input is:')
        for pts in points:
            print(pts)

        print('\nWhich algorithm would you like to test?')
        print('1) nearest neighbor ')
        print('2) exhaustive ')
        print('3) both ')
        choice = int(input('Enter number: '))

        if choice in [1, 3]:
            print('\nTesting nearest_neighbor algorithm')
            print('==================================')

            # call function before enter loop to ensure identical three trials
            distance, path = nearest_neighbor(list(points))

            clocked_at = []
            for i in range(3):
                del distance, path
                start = time.time()
                distance, path = nearest_neighbor(list(points))
                clocked_at.append(time.time() - start)

            format_results(distance, path, clocked_at)

        if choice in [2, 3]:
            print('\nTesting exhaustive algorithm')
            print('==================================')

            # call function before enter loop to ensure identical three trials
            distance, path = exhaustive_tsp(list(points))

            clocked_at = []
            for i in range(3):
                del distance, path
                start = time.time()
                distance, path = exhaustive_tsp(list(points))
                clocked_at.append(time.time() - start)

            format_results(distance, path, clocked_at)

        print('Repeat? (y/n)')
        if input().lower() != 'y':
            break


if __name__ == '__main__':
    main()
