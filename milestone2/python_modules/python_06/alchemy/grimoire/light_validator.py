#!/usr/bin/env python3.10

import alchemy.grimoire


def validate_ingredients(ingredients: str) -> str:
    for elm in ingredients.split(" "):
        for valid in alchemy.grimoire.light_spell_allowed_ingredients():
            if (elm.lower() == valid.lower()):
                return ("VALID")
    return ("INVALID")
