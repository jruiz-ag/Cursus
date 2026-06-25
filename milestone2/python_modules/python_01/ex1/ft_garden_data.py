#!/usr/bin/env python3.10

class Plant:
    def __init__(self, name: str, height: int, age_days: int) -> None:
        self.name: str = name
        self.height: int = height
        self.age_days: int = age_days

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")


def main() -> None:
    print("=== Garden Plant Registry ===")
    plant_1: Plant = Plant("Rose", 25, 30)
    plant_2: Plant = Plant("Sunflower", 80, 45)
    plant_3: Plant = Plant("Cactus", 15, 120)
    plant_1.show()
    plant_2.show()
    plant_3.show()


if __name__ == "__main__":
    main()
