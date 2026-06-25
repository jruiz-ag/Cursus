#!/usr/bin/env python3.10

def ft_count_harvest_recursive(num: int = -1, acumulative: int = 1) -> None:
    if (num == -1):
        num = int(input("Days until harvest: "))
    if (num > 0):
        print(f"Day {acumulative}")
        ft_count_harvest_recursive(num - 1, acumulative + 1)
    else:
        print("Harvest time!")
