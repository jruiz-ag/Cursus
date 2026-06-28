#!/usr/bin/env python3.10

import sys
import typing


def first_part(file: typing.IO) -> list:
    transform_data: list = []

    print("---\n")
    text: str = file.read()
    cont: int = 1
    for line in text.split("\n"):
        print(line)
        transform_data.append(f"{line}#")
        cont += 1
    return (transform_data)


def main() -> None:
    if (len(sys.argv) != 2):
        print("Usage: ft_ancient_text.py <file>")
        return

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accesing file '{sys.argv[1]}'")
    try:
        file: typing.IO = open(sys.argv[1], "r")
        transform_data: list = first_part(file)
    except (FileNotFoundError, PermissionError) as ex:
        print(f"Error opening file '{sys.argv[1]}': {ex}")
        return
    else:
        print(f"\n---\nFile '{sys.argv[1]}' closed.")
        file.close()
    print("\nTransform data:")
    print("---\n")

    print('\n'.join(transform_data))
    print("\n---")

    dest_file: str = input("Enter new file name (or empty): ")
    if (len(dest_file.strip()) == 0):
        print("Not saving data.")
        return

    try:
        print(f"Saving data to '{dest_file}'")
        file = open(dest_file, "w")
        for line in transform_data:
            file.write(f"{line}")
            if (line != transform_data[-1]):
                file.write("\n")
    except (FileNotFoundError, PermissionError) as ex:
        print(f"Error opening file '{sys.argv[1]}': {ex}")
    else:
        print(f"Data saved in file '{dest_file}'")


if __name__ == "__main__":
    main()
