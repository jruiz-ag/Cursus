#!/usr/bin/env python3.10

import alchemy.grimoire.dark_spellbook


def main() -> None:
    print("=== Kaboom 1 ===")
    print("Using grimoire module directly")

    elms: str = "Bats, eyes and frogs"
    name: str = "Fantasy"
    text: str = alchemy.grimoire.dark_spellbook.dark_spell_record(name, elms)
    print(f"Testing record light spell: {text}")


if __name__ == "__main__":
    main()
