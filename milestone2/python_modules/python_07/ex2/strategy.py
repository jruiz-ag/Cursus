#!/usr/bin/env python3.10

import abc
from ex0.creatures import Creature
from ex1.capabilities import HealCapability, TransformCapability


class BattleStrategy(abc.ABC):
    @abc.abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass

    @abc.abstractmethod
    def act(self, creature: Creature) -> None:
        pass


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return (True)

    def act(self, creature: Creature) -> None:
        if not (self.is_valid(creature)):
            raise Exception
        print(creature.attack())


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, TransformCapability):
            return (True)
        return (False)

    def act(self, creature: Creature) -> None:
        if not (self.is_valid(creature)):
            text = f"Invalid Creature '{creature.__class__.__name__}' "
            text += "for this aggressive strategy"
            raise Exception(text)
        if isinstance(creature, TransformCapability):
            print(creature.transform())
            print(creature.attack())
            print(creature.revert())


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, HealCapability):
            return (True)
        return (False)

    def act(self, creature: Creature) -> None:
        if not (self.is_valid(creature)):
            text = f"Invalid Creature '{creature.__class__.__name__}' "
            text += "for this defensive strategy"
            raise Exception(text)
        if isinstance(creature, HealCapability):
            print(creature.attack())
            print(creature.heal())
