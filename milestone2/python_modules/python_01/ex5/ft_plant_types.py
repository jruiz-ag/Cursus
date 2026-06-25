#!/usr/bin/env python3.10

class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        if (height < 0 or age_days < 0):
            print("The creation is not possible")
            return
        self.track_growth: float = 0
        self._name: str = name
        self._height: float = height
        self._age_days: int = age_days
        self.show()

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_days

    def get_name(self) -> str:
        return self._name

    def set_height(self, height: int) -> None:
        if (height < 0):
            print(f"{self.get_name()}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {self.get_height()}cm")

    def set_age(self, age: int) -> None:
        if (age < 0):
            print(f"{self.get_name()}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age_days = age
            print(f"Age updated: {self.get_age()} days")

    def age(self, days: int = 1) -> None:
        self._age_days += days

    def grow(self, change: float = 2.1) -> float:
        self._height += change
        return (change)

    def track_week(self) -> None:
        print("=== Garden Plant Growth ===")
        self.show()
        for i in range(7):
            self.track_growth += self.grow()
            print(f"=== Day {i + 1} ===")
            self.show()
        print(f"Growth this week: {round(self.track_growth, 1)}cm")

    def show(self) -> None:
        round_height = round(self.get_height(), 1)
        print(f"{self.get_name()}: ", end="")
        print(f"{round_height}cm, {self.get_age()} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float,
                 age_days: int, color: str) -> None:
        self.color: str = color
        self.is_bloom: bool = False
        super().__init__(name, height, age_days)

    def bloom(self) -> None:
        self.is_bloom = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.is_bloom:
            print(f" {super().get_name()} is blooming beautifully!")
        else:
            print(f" {super().get_name()} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float,
                 age_days: int, trunk_diameter: float) -> None:
        self.trunk_diameter: float = trunk_diameter
        super().__init__(name, height, age_days)

    def produce_shade(self) -> None:
        print(f"Tree {super().get_name()} now produces a shade of ", end="")
        print(f"{super().get_height()}cm long", end="")
        print(f" and {self.trunk_diameter}cm wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age_days: int,
                 harvest_season: str, nutritional_value: int = 0) -> None:
        self.harvest_season: str = harvest_season
        self.nutritional_value: int = nutritional_value
        super().__init__(name, height, age_days)

    def make_grow(self, days: int) -> None:
        self.nutritional_value += days
        for _ in range(days):
            super().grow()
            super().age()

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")

    plant_1: Flower = Flower("Rose", 15.0, 10, "red")
    print("[asking the rose to bloom]")
    plant_1.bloom()
    plant_1.show()

    print("\n=== Tree")
    plant_2: Tree = Tree("Oak", 200.0, 365, 5.0)
    print("[asking the oak to produce shade]")
    plant_2.produce_shade()

    print("\n=== Vegetable")
    plant_3: Vegetable = Vegetable("Tomato", 5.0, 10, "April")
    print("[make tomato grow and age for 20 days]")
    plant_3.make_grow(20)
    plant_3.show()


if __name__ == "__main__":
    main()
