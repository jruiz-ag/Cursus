#!/usr/bin/env python3.10

from ex0.creatures import Creature
from ex1.capabilities import TransformCapability


class Shiftling(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Shiftling", "Normal")
        self.shifted = False

    def attack(self) -> str:
        if not self.shifted:
            return (f"{self.name} attacks normally.")
        else:
            return (f"{self.name} performs a boosted strike!")

    def transform(self) -> str:
        self.shifted = True
        return (f"{self.name} shifts into a sharper form!")

    def revert(self) -> str:
        return (f"{self.name} returns to normal.")


class Morphagon(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Morphagon", "Normal/Dragon")
        self.shifted = False

    def attack(self) -> str:
        if not self.shifted:
            return (f"{self.name} attacks normally.")
        else:
            return (f"{self.name} unleashes a devastating morph strike!")

    def transform(self) -> str:
        self.shifted = True
        return (f"{self.name} morphs into a dragonic battle form!")

    def revert(self) -> str:
        self.shifted = False
        return (f"{self.name} stabilizes its form.")
