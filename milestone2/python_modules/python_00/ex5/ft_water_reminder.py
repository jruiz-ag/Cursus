#!/usr/bin/env python3.10

def ft_water_reminder() -> None:
    days_after: int = int(input("Days since last watering: "))
    if (days_after > 2):
        print("Water the plants!")
    else:
        print("Plants are fine")
