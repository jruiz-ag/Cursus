#!/usr/bin/env python3.10

from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import BattleStrategy, NormalStrategy
from ex2 import AggressiveStrategy, DefensiveStrategy


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    for (cont, combination1) in enumerate(opponents):
        creature1 = combination1[0].create_base()
        for (combination2) in opponents[(cont + 1):]:
            print()
            creature2 = combination2[0].create_base()
            print("* Battle *")
            print(creature1.describe())
            print(" vs.")
            print(creature2.describe())
            print(" now fight!")
            try:
                combination1[1].act(creature1)
                (combination2[1].act(creature2))
            except Exception as ex:
                print(f"Battle error, aborting tournament: {ex}")
    print()


def main() -> None:
    print("Tournament 0 (basic)")
    print("[ (Flameling+Normal), (Healing+Defensive) ]")
    list_1: list = [(FlameFactory(), NormalStrategy()),
                    (HealingCreatureFactory(), DefensiveStrategy())]
    battle(list_1)

    print("Tournament 1 (error)")
    print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
    list_2: list = [(FlameFactory(), AggressiveStrategy()),
                    (HealingCreatureFactory(), DefensiveStrategy())]
    battle(list_2)

    print("Tournament 2 (multiple)")
    print("[ (Aquabub+Normal), (Healing+Defensive), ", end="")
    print("(Transform+Aggressive) ]")
    list_3: list = [(AquaFactory(), NormalStrategy()),
                    (HealingCreatureFactory(), DefensiveStrategy()),
                    (TransformCreatureFactory(), AggressiveStrategy())]
    battle(list_3)


if __name__ == "__main__":
    main()
