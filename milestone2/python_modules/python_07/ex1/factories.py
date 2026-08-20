#!/usr/bin/env python3.10

from ex0.factories import CreatureFactory
from ex1.healing import Sproutling, Bloomelle
from ex1.transforming import Shiftling, Morphagon


class HealingCreatureFactory(CreatureFactory):
    def create_base(self) -> Sproutling:
        return (Sproutling())

    def create_evolved(self) -> Bloomelle:
        return (Bloomelle())


class TransformCreatureFactory(CreatureFactory):
    def create_base(self) -> Shiftling:
        return (Shiftling())

    def create_evolved(self) -> Morphagon:
        return (Morphagon())
