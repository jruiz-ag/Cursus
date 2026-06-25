#!/usr/bin/env python3.10

def ft_count_harvest_iterative() -> None:
    days_until: int = int(input("Days until harvest: "))
    for i in range(days_until):
        print(f"Day {i + 1}")
    print("Harvest time!")
