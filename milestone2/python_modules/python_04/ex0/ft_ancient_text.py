#!/usr/bin/env python3.10

import sys
import typing


def zeros(cont: int) -> str:
    len_int: int = 0
    while (cont > 0):
        len_int += 1
        cont //= 10
    num_zeros = 3 - len_int
    if (num_zeros > 0):
        return ("0" * num_zeros)
    return ("")


def main() -> None:
    if (len(sys.argv) != 2):
        print("Usage: ft_ancient_text.py <file>")
        return

    print("=== Cyber Archives Recovery ===")
    print(f"Accesing file '{sys.argv[1]}'")
    try:
        file: typing.IO = open(sys.argv[1], "r")
        print("---\n")
        text: str = file.read()
        cont: int = 1
        for line in text.split("\n"):
            print(line)
            cont += 1
    except (FileNotFoundError, PermissionError) as ex:
        print(f"Error opening file '{sys.argv[1]}': {ex}")
    else:
        print("\n---")
        print(f"File '{sys.argv[1]}' closed.")
        file.close()


if __name__ == "__main__":
    main()
