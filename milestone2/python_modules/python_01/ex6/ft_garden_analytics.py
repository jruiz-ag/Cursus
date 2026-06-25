#!/usr/bin/env python3.10

def show_statistics(plant: "Plant") -> None:
    plant.count.show()


class Plant:
    class CountClass:
        def __init__(self) -> None:
            self.count_grow: int = 0
            self.count_age: int = 0
            self.count_show: int = 0

        def show(self) -> None:
            print(f"Stats: {self.count_grow} grow, {self.count_age}", end="")
            print(f" age, {self.count_show} show")

    def __init__(self, name: str, height: float, age_days: int) -> None:
        if (height < 0 or age_days < 0):
            print("The creation is not possible")
            height = 0
            age_days = 0
        self.track_growth: float = 0
        self._name: str = name
        self._height: float = height
        self._age_days: int = age_days
        self.count = Plant.CountClass()
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
        self.count.count_age += 1

    def grow(self, increase: int = 8) -> float:
        change = increase
        self._height += change
        self.count.count_grow += 1
        return (change)

    def track_week(self) -> None:
        print("=== Garden Plant Growth ===")
        self.show()
        for i in range(7):
            self.track_growth += self.grow()
            print(f"=== Day {i + 1} ===")
            self.show()
        print(f"Growth this week: {round(self.track_growth, 1)}cm")

    @staticmethod
    def static_method(age: int) -> bool:
        if (age > 365):
            return (True)
        else:
            return (False)

    @classmethod
    def class_method(cls) -> "Plant":
        return (cls("Unknown plant", 0.0, 0))

    def show(self) -> None:
        self.count.count_show += 1
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
        self.count_shades = 0
        super().__init__(name, height, age_days)

    def produce_shade(self) -> None:
        print(f"Tree {super().get_name()} now produces a shade of ", end="")
        print(f"{super().get_height()}cm long", end="")
        print(f" and {self.trunk_diameter}cm wide.")
        self.count_shades += 1

    def show_statistics(self) -> None:
        show_statistics(self)
        print(f" {self.count_shades} shade")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age_days: int,
                 harvest_season: str, nutritional_value: int) -> None:
        self.harvest_season: str = harvest_season
        self.nutritional_value: int = nutritional_value
        super().__init__(name, height, age_days)

    def make_grow(self, days: int) -> None:
        self.nutritional_value += days
        for _ in range(days):
            super().grow()

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


class Seed(Flower):
    def __init__(self, name: str, height: float, age_days: int,
                 color: str, seeds: int) -> None:
        self.seeds: int = seeds
        super().__init__(name, height, age_days, color)

    def grow(self, days: int = 8) -> float:
        if self.is_bloom:
            self.seeds += 42
        return (super().grow(days))

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seeds}")


def main() -> None:
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.static_method(30)}")
    print(f"Is 400 days more than a year? -> {Plant.static_method(400)}")

    print("\n=== Flower")
    plant_1: Flower = Flower("Rose", 15.0, 10, "red")
    print("[statistics for Rose]")
    show_statistics(plant_1)
    print("[asking the rose to grow and bloom]")
    plant_1.grow()
    plant_1.bloom()
    plant_1.show()
    print("[statistics for Rose]")
    show_statistics(plant_1)

    print("\n=== Tree")
    plant_2: Tree = Tree("Oak", 200.0, 365, 5.0)
    print("[statistics for Oak]")
    plant_2.show_statistics()
    print("[asking the oak to produce shade]")
    plant_2.produce_shade()
    print("[statistics for Oak]")
    plant_2.show_statistics()

    print("\n=== Seed")
    plant_3: Seed = Seed("Sunflower", 80.0, 45, "yellow", 0)
    print("[make sunflower grow, age and bloom]")
    plant_3.grow(30)
    plant_3.age(20)
    plant_3.bloom()
    plant_3.show()
    print("[statistics for Sunflower]")
    show_statistics(plant_3)

    print("\n=== Anonymous")
    plant_4: Plant = Plant.class_method()
    print("[statistics for Unknown plant]")
    show_statistics(plant_4)


if __name__ == "__main__":
    main()
