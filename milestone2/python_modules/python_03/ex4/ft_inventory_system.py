#!/usr/bin/env python3.10

import sys


def main() -> None:
    print("=== Inventory System Analysis ===")
    if (len(sys.argv) <= 1):
        print("No valid items provided")
    else:
        valids: dict = dict()
        for vals in sys.argv[1:]:
            try:
                key_value = vals.split(":")
                if len(key_value) != 2:
                    raise Exception(f"invalid parameter '{vals}'")
                if (len(key_value[0]) < 1) or (len(key_value[1]) < 1):
                    raise Exception(f"invalid parameter '{vals}'")
                int(key_value[1])
            except ValueError as ex:
                print(f"Quantity error for '{key_value[0]}': {ex}")
            except Exception as ex:
                print(f"Error - {ex}")
            else:
                if (key_value[0].strip()) in valids.keys():
                    print(f"Redundant item '{key_value[0].strip()}'", end="")
                    print(" - discarding")
                else:
                    valids.update({key_value[0].strip(): key_value[1].strip()})
        print(f"Got inventory: {valids}")


if __name__ == "__main__":
    main()
