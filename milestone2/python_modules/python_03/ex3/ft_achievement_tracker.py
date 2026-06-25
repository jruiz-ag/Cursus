#!/usr/bin/env python3.10

import random


def gen_player_achievements() -> set:
    achievements: set = set(("Crafting Genius", "World Savior",
                             "Master Explorer", "Collector Supreme",
                             "Untouchable", "Boss Slayer", "Strategist",
                             "Unstoppable", "Sharp Mind", "First Steps",
                             "Hidden Path Finder", "Survivor",
                             "Treasure Hunter"))
    choiced: set = set()
    for ach in achievements:
        if (random.randint(0, 1) == 1):
            choiced.add(ach)
    if (len(choiced) == 0):
        choiced.add("Survivor")
    return (choiced)


def extract_dist(p1: set, p2: set, p3: set, p4: set) -> set:
    achievements: set = set(("Crafting Genius", "World Savior",
                             "Master Explorer", "Collector Supreme",
                             "Untouchable", "Boss Slayer", "Strategist",
                             "Unstoppable", "Sharp Mind", "First Steps",
                             "Hidden Path Finder", "Survivor",
                             "Treasure Hunter"))
    commons: set = (p1.intersection(p2).intersection(p3).intersection(p4))
    return (achievements.difference(commons))


def extract_comm(p1: set, p2: set, p3: set, p4: set) -> set:
    return (p1.intersection(p2).intersection(p3).intersection(p4))


def extract_uniq(p1: set, p2: set, p3: set, p4: set) -> set:
    return (p1.difference(p2).difference(p3).difference(p4))


def missing_ones(person: set) -> set:
    achievements: set = set(("Crafting Genius", "World Savior",
                             "Master Explorer", "Collector Supreme",
                             "Untouchable", "Boss Slayer", "Strategist",
                             "Unstoppable", "Sharp Mind", "First Steps",
                             "Hidden Path Finder", "Survivor",
                             "Treasure Hunter"))
    return (achievements.difference(person))


def main() -> None:
    print("=== Achievement Tracker System ===\n")

    alice: set = gen_player_achievements()
    print(f"Player Alice: {alice}")
    bob: set = gen_player_achievements()
    print(f"Player Bob: {bob}")
    charlie: set = gen_player_achievements()
    print(f"Player Charlie: {charlie}")
    dylan: set = gen_player_achievements()
    print(f"Player Dylan: {dylan}")

    print("\nAll distinct achievements: ", end="")
    print(extract_dist(alice, bob, charlie, dylan))
    print("\nCommon achievements: ", end="")
    print(extract_comm(alice, bob, charlie, dylan))

    print(f"\nOnly Alice has: {extract_uniq(alice, bob, charlie, dylan)}")
    print(f"Only Bob has: {extract_uniq(bob, alice, charlie, dylan)}")
    print(f"Only Charlie has: {extract_uniq(charlie, bob, alice, dylan)}")
    print(f"Only Dylan has: {extract_uniq(dylan, bob, charlie, alice)}")

    print(f"\nAlice is missing: {missing_ones(alice)}")
    print(f"Bob is missing: {missing_ones(bob)}")
    print(f"Charlie is missing: {missing_ones(charlie)}")
    print(f"Dylan is missing: {missing_ones(dylan)}")


if __name__ == "__main__":
    main()
