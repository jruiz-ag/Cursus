#!/usr/bin/env python3.10

import alchemy.transmutation.recipes


def main() -> None:
    print("=== Transmutation 0 ===")
    print("Using file alchemy/transmutation/recipes.py directly")
    print("Testing lead to gold: ", end="")
    print(alchemy.transmutation.recipes.lead_to_gold())


if __name__ == "__main__":
    main()
