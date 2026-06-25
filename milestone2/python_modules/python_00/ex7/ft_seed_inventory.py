#!/usr/bin/env python3.10

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if (unit != "packets" and unit != "grams" and unit != "area"):
        print("Unknown unit type")
    else:
        extra: str = ""
        if (unit == "area"):
            extra = " covers"
        print(f"{seed_type.capitalize()} seeds:{extra} {quantity} ", end="")
        if (unit == "grams"):
            print("grams total")
        elif (unit == "packets"):
            print("packets available")
        else:
            print("square meters")
