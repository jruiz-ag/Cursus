#!/usr/bin/env python3.10

import sys


def main() -> None:
    print("=== Comand Quest ===")

    print("Program name: ft_command_quest.py")
    if len(sys.argv) <= 1:
        print("No arguments provided!")
    else:
        cont: int = 1
        print(f"Arguments received: {len(sys.argv) - 1}")
        for arg_str in sys.argv[1:]:
            print(f"Argument {cont}: {arg_str}")
            cont += 1

    print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    main()
