#!/usr/bin/env python3.10

import ex0.creatures
import abc


class CreatureFactory(abc.ABC):
    @abc.abstractmethod
    def create_base(self) -> ex0.creatures.Creature:
        pass

    @abc.abstractmethod
    def create_evolved(self) -> ex0.creatures.Creature:
        pass


class FlameFactory(CreatureFactory):
    def create_base(self) -> ex0.creatures.Creature:
        return (ex0.creatures.Flameling())

    def create_evolved(self) -> ex0.creatures.Creature:
        return (ex0.creatures.Pyrodon())


class AquaFactory(CreatureFactory):
    def create_base(self) -> ex0.creatures.Creature:
        return (ex0.creatures.Aquabub())

    def create_evolved(self) -> ex0.creatures.Creature:
        return (ex0.creatures.Torragon())
