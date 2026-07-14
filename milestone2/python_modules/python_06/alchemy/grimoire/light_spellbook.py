#!/usr/bin/env python3.10

import alchemy.grimoire


def light_spell_allowed_ingredients() -> list:
    return (["earth", "air", "fire", "water"])


def light_spell_record(spell_name: str, ingredients: str) -> str:
    text: str = f"Spell recorded: {spell_name} ({ingredients} - "
    text += f"{alchemy.grimoire.validate_ingredients(ingredients)})"
    return (text)
