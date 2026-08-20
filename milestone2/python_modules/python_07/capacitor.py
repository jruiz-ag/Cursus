#!/usr/bin/env python3.10

from ex1 import HealingCreatureFactory, TransformCreatureFactory


def main() -> None:
    print("Testing Creature with healing capability")
    print(" base:")
    factory_1 = HealingCreatureFactory()
    first_creature = factory_1.create_base()
    print(first_creature.describe())
    print(first_creature.attack())
    print(first_creature.heal())

    print(" evolved:")
    first_evolved = factory_1.create_evolved()
    print(first_evolved.describe())
    print(first_evolved.attack())
    print(first_evolved.heal())

    print("\nTesting Creature with transform capability")
    print(" base:")
    factory_2 = TransformCreatureFactory()
    second_creature = factory_2.create_base()
    print(second_creature.describe())
    print(second_creature.attack())
    print(second_creature.transform())
    print(second_creature.attack())
    print(second_creature.revert())

    print(" evolved:")
    second_evolved = factory_2.create_evolved()
    print(second_evolved.describe())
    print(second_evolved.attack())
    print(second_evolved.transform())
    print(second_evolved.attack())
    print(second_evolved.revert())


if __name__ == "__main__":
    main()
