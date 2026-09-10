#!/usr/bin/env python3.10

import sys
import typing


def main() -> None:
    if (len(sys.argv) != 2):
        print("Usage: ft_ancient_text.py <file>")
        return

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        file: typing.IO = open(sys.argv[1], "r")
        print("---\n")
        text: str = file.read()
        for line in text.split("\n"):
            print(line)
    except (FileNotFoundError, PermissionError) as ex:
        print(f"Error opening file '{sys.argv[1]}': {ex}")
    else:
        print("---")
        print(f"File '{sys.argv[1]}' closed.")
        file.close()


if __name__ == "__main__":
    main()
