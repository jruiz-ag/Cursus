#!/usr/bin/env python3.10

import elements as superelm
from alchemy import elements as subelm


def healing_potion() -> str:
    text: str = f"Healing potion brewed with '{subelm.create_earth()}'"
    text += f" and '{subelm.create_air()}'"
    return (text)


def strength_potion() -> str:
    text: str = f"Strength potion brewed with '{superelm.create_fire()}'"
    text += f" and '{superelm.create_water()}'"
    return (text)
