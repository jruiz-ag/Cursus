#!/usr/bin/env python3.10

import math


def get_player_pos() -> tuple:
    while True:
        try:
            c3d = input("Enter new coordinates as float in format 'x,y,z': ")
            values: list = c3d.split(",")
            values[0], values[1], values[2]
            try:
                values[3]
            except IndexError:
                pass
            else:
                raise IndexError
            trying: str = values[0].strip()
            num_1 = float(trying)
            trying = values[1].strip()
            num_2 = float(trying)
            trying = values[2].strip()
            num_3 = float(trying)
        except IndexError:
            print("Invalid syntax")
        except ValueError as ex:
            print(f"Error on parameter '{trying}': {ex}")
        else:
            return (num_1, num_2, num_3)


def calc_distance(val_1: tuple, val_2: tuple) -> float:
    s_1: float = (val_1[0] - val_2[0])**2
    s_2: float = (val_1[1] - val_2[1])**2
    s_3: float = (val_1[2] - val_2[2])**2
    return (math.sqrt(s_1 + s_2 + s_3))


def main() -> None:
    print("=== Game Coordinate System ===")

    print("\nGet a first set of coordinates")
    c_1: tuple = get_player_pos()
    print(f"Got a first tuple: {c_1}")
    print(f"It includes: X={c_1[0]}, Y={c_1[1]}, Z={c_1[2]}")
    dist_center: float = calc_distance(c_1, (0, 0, 0))
    print(f"Distance to center: {round(dist_center, 4)}")

    print("\nGet a second set of coordinates")
    c_2: tuple = get_player_pos()
    dist_between: float = calc_distance(c_1, c_2)
    print("Distance between the 2 sets of coordinates: ", end="")
    print(round(dist_between, 4))


if __name__ == "__main__":
    main()
