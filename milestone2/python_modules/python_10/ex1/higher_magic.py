from collections.abc import Callable

def spell(target: str, power: int) -> str:
    return (f"{target} is overpowered with an attack of {power}")


def heal(target: str, power: int) -> str:
    return (f"Heal restores {target} for {power} HP")


def eat(target: str, power: int) -> str:
    return (f"Eating makes {target} recover {power} points")


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined_spell(target: str, power: int) -> str:
        return (f"{spell1(target, power)}, {spell2(target, power)}")
    return (combined_spell)

def main() -> None:
    """ Execute the whole tests """

    print("\nTesting spell combiner...")
    call_1: Callable = spell_combiner(heal, eat)
    print(f"Combined spell result: {call_1('Dragon', 3)}")

if __name__ == "__main__":
    main()