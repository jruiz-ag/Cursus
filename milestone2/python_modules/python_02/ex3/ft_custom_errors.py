#!/usr/bin/env python3.10

class GardenError(Exception):
    def __init__(self, msg: str = 'Unknown plant error') -> None:
        Exception.__init__(self, msg)


class PlantError(GardenError):
    def __init__(self, msg: str = 'Unknown plant error') -> None:
        GardenError.__init__(self, msg)


class WaterError(GardenError):
    def __init__(self, msg: str = 'Unknown plant error') -> None:
        GardenError.__init__(self, msg)


def main() -> None:
    print("=== Custom Garden Errors Demo ===")

    print("\nTesting PlantError...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except PlantError as ex:
        print(f"Caught PlantError: {ex}")

    print("\nTesting WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as ex:
        print(f"Caught WaterError: {ex}")

    print("\nTesting catching all garden errors...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except GardenError as ex:
        print(f"Caught GardenError: {ex}")
    try:
        raise WaterError("Not enough water in the tank!")
    except GardenError as ex:
        print(f"Caught GardenError: {ex}")

    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    main()
