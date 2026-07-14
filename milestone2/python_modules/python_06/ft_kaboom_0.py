#!/usr/bin/env python3.10

import alchemy.grimoire


def main() -> None:
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")

    elms: str = "Earth, wind and fire"
    name: str = "Fantasy"
    text: str = alchemy.grimoire.light_spell_record(name, elms)
    print(f"Testing record light spell: {text}")


if __name__ == "__main__":
    main()
