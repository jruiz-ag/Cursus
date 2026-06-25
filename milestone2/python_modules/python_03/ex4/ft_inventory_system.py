#!/usr/bin/env python3.10

import sys


def show_script(valids: dict) -> None:
    total: int = sum(list(valids.values()))
    print(f"Got inventory: {valids}")
    print(f"Item list: {list(valids.keys())}")
    print(f"Total quality of the {len(list(valids.keys()))} items: ", end="")
    print(total)
    for item in valids.keys():
        print(f"Item {item} represents {round(valids[item]/total * 100, 1)}%")
    max: int = -1
    str_max: str = ""
    for item in valids.keys():
        if ((valids[item] > max) or (max == -1)):
            max = valids[item]
            str_max = item
    print(f"Item most abundant: {str_max} with quantity {max}")
    min: int = -1
    str_min: str = ""
    for item in valids.keys():
        if ((valids[item] < min) or (min == -1)):
            min = valids[item]
            str_min = item
    print(f"Item least abundant: {str_min} with quantity {min}")


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
                    key: str = key_value[0].strip()
                    val: int = int(key_value[1].strip())
                    valids.update({key: val})
        if (len(valids) <= 0):
            print("No valid items provided")
        else:
            show_script(valids)
            valids.update({"magic_item": 1})
            print(f"Updated inventory: {valids}")


if __name__ == "__main__":
    main()
