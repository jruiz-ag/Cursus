#!/usr/bin/env python3.10

from ex0 import CreatureFactory, FlameFactory, AquaFactory


def verify_factory(factory: CreatureFactory) -> None:
    print("Testing factory")
    first_creature = factory.create_base()
    print(first_creature.describe())
    print(first_creature.attack())

    first_evolved = factory.create_evolved()
    print(first_evolved.describe())
    print(first_evolved.attack())

    print()


def make_fight(factory1: FlameFactory,
               factory2: AquaFactory) -> None:
    first_creature = factory1.create_base()
    second_creature = factory2.create_base()

    print("Testing battle")
    print(first_creature.describe())
    print(" vs.")
    print(second_creature.describe())
    print(" fight!")
    print(first_creature.attack())
    print(second_creature.attack())

    print()


def main() -> None:
    flame_factory = FlameFactory()
    verify_factory(flame_factory)

    aqua_factory = AquaFactory()
    verify_factory(aqua_factory)

    make_fight(flame_factory, aqua_factory)


if __name__ == "__main__":
    main()
