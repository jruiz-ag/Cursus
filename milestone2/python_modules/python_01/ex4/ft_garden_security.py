class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        if (height < 0 or age_days < 0):
            print("The creation has bad values")
            height = 0
            age_days = 0
        self.track_growth: float = 0
        self.name: str = name
        self._height: float = height
        self._age_days: int = age_days
        print("Plant created: ", end="")
        self.show()

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_days

    def set_height(self, height: int) -> None:
        if (height < 0):
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {self.get_height()}cm")

    def set_age(self, age: int) -> None:
        if (age < 0):
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age_days = age
            print(f"Age updated: {self.get_age()} days")

    def age(self, days: int = 1) -> None:
        self._age_days += days

    def grow(self, change: float = 0.8) -> float:
        self._height += change
        return (change)

    def track_week(self) -> None:
        print("=== Garden Plant Growth ===")
        self.show()
        for i in range(7):
            self.track_growth += self.grow()
            self.age()
            print(f"=== Day {i + 1} ===")
            self.show()
        print(f"Growth this week: {round(self.track_growth, 1)}cm")

    def show(self) -> None:
        round_height = round(self.get_height(), 1)
        print(f"{self.name}: {round_height}cm, {self.get_age()} days old")


def main() -> None:
    print("=== Garden Security System ===")
    plant = Plant("Rose", 15.0, 10)
    print()
    plant.set_height(25)
    plant.set_age(30)
    print()
    plant.set_height(-3)
    plant.set_age(-1)
    print("\nCurrent state: ", end="")
    plant.show()


if __name__ == "__main__":
    main()
