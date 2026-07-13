#!/usr/bin/env python3.10

from ..elements import create_air
from alchemy import strength_potion
import elements


def lead_to_gold() -> str:
    text: str = "Recipe transmuting Lead to Gold: brew"
    text += f" '{create_air()}' and '{strength_potion()}'"
    text += f" mixed with '{elements.create_fire()}'"
    return (text)
