#!/usr/bin/env python3.10

import random


def main() -> None:
    print("=== Game Data Alchemist ===")

    init: list = ["Alice", "bob", "Charlie", "dylan", "Emma", "Gregory",
                  "john", "kevin", "Liam"]
    print(f"\nInitial list of players: {init}")

    first: list = [elm.capitalize() for elm in init]
    print(f"New list with all names capitalized: {first}")

    second: list = [elm for elm in init if elm.capitalize() == elm]
    print(f"New list of capitalized names only {second}")

    third: dict = {key: random.randint(50, 910) for key in first}
    sum: int = 0
    for elm in third:
        sum += third[elm]
    print(f"\nScore dict: {third}")
    average: float = round(sum/len(third), 2)
    print(f"Score average is {average}")

    fourth: dict = {key: third[key] for key in third if third[key] > average}
    print(f"High scores: {fourth}")


if __name__ == "__main__":
    main()
