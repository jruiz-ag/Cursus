#!/usr/bin/env python3.10

def main() -> None:
    print("=== Kaboom 1 ===")
    print("Access to alchemy/grimoire/dark_spellbook.py directly")
    print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")

    import alchemy.grimoire.dark_spellbook

    elms: str = "Bats, eyes and frogs"
    name: str = "Fantasy"
    text: str = alchemy.grimoire.dark_spellbook.dark_spell_record(name, elms)
    print(f"Testing record light spell: {text}")


if __name__ == "__main__":
    main()
