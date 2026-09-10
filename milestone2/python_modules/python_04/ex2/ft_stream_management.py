#!/usr/bin/env python3.10

import sys
import typing


def first_part(file: typing.IO) -> list:
    transform_data: list = []

    print("---\n")
    text: str = file.read()
    for line in text.split("\n"):
        print(line)
        if (len(line) != 0):
            transform_data.append(f"{line}#")
        else:
            transform_data.append(f"{line}")
    return (transform_data)


def main() -> None:
    if (len(sys.argv) != 2):
        print("Usage: ft_stream_management.py <file>", file=sys.stdout)
        return

    print("=== Cyber Archives Recovery & Preservation ===", file=sys.stdout)
    print(f"Accessing file '{sys.argv[1]}'", file=sys.stdout)
    try:
        file: typing.IO = open(sys.argv[1], "r")
        transform_data: list = first_part(file)
    except (FileNotFoundError, PermissionError) as ex:
        print("[STDERR] Error opening file ", end="", file=sys.stderr)
        print(f"'{sys.argv[1]}': {ex}", file=sys.stderr)
        return
    else:
        print(f"\n---\nFile '{sys.argv[1]}' closed.", file=sys.stdout)
        file.close()
    print("\nTransform data:", file=sys.stdout)
    print("---\n", file=sys.stdout)

    print('\n'.join(transform_data), file=sys.stdout)
    print("---", file=sys.stdout)

    print("Enter new file name (or empty): ", end="", file=sys.stdout)
    sys.stdout.flush()
    dest_file: str = sys.stdin.readline().strip()
    if (len(dest_file.strip()) == 0):
        print("Data not saved.", file=sys.stdout)
        return

    try:
        print(f"Saving data to '{dest_file}'", file=sys.stdout)
        file = open(dest_file, "w")
        max_line = len(transform_data)
        cont_line = 0
        for line in transform_data:
            cont_line += 1
            file.write(f"{line}")
            if (cont_line != max_line):
                file.write("\n")
    except (FileNotFoundError, PermissionError) as ex:
        print("[STDERR] Error opening file ", end="", file=sys.stderr)
        print(f"'{dest_file}': {ex}", file=sys.stderr)
        print("Data not saved.", file=sys.stdout)
    else:
        print(f"Data saved in file '{dest_file}'", file=sys.stdout)


if __name__ == "__main__":
    main()
