#!/usr/bin/env python3.10

from .dark_spellbook import dark_spell_allowed_ingredients


def dark_validate_ingredients(ingredients: str) -> str:
    for elm in ingredients.split(" "):
        for valid in dark_spell_allowed_ingredients():
            if (elm.lower() == valid.lower()):
                return ("VALID")
    return ("INVALID")
