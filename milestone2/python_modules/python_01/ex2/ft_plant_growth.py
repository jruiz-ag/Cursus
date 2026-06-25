#!/usr/bin/env python3.10

class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.track_growth: float = 0
        self.name: str = name
        self.height: float = height
        self.age_days: int = age_days

    def age(self) -> None:
        self.age_days += 1

    def grow(self) -> float:
        change = 0.8
        self.height += change
        self.age()
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
        round_height = round(self.height, 1)
        print(f"{self.name}: {round_height}cm, {self.age_days} days old")


def main() -> None:
    plant: Plant = Plant("Rose", 25.0, 30)
    plant.track_week()


if __name__ == "__main__":
    main()
