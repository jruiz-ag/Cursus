#!/usr/bin/env python3.10

from .dark_validator import dark_validate_ingredients


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    text: str = f"Spell recorded: {spell_name} ({ingredients} - "
    text += f"{dark_validate_ingredients(ingredients)})"
    return (text)


def dark_spell_allowed_ingredients() -> list:
    return (["bats", "frogs", "arsenic", "eyeball"])
