#!/usr/bin/env python3.10

from ex0 import FlameFactory, AquaFactory


def main() -> None:
    print("Testing factory")
    flame_factory = FlameFactory()
    first_creature = flame_factory.create_base()
    print(first_creature.describe())
    print(first_creature.attack())

    first_evolved = flame_factory.create_evolved()
    print(first_evolved.describe())
    print(first_evolved.attack())

    print("\nTesting factory")
    aqua_factory = AquaFactory()
    second_creature = aqua_factory.create_base()
    print(second_creature.describe())
    print(second_creature.attack())

    second_evolved = aqua_factory.create_evolved()
    print(second_evolved.describe())
    print(second_evolved.attack())

    print("\nTesting battle")
    print(first_creature.describe())
    print(second_creature.describe())
    print(first_creature.attack())
    print(second_creature.attack())


if __name__ == "__main__":
    main()
