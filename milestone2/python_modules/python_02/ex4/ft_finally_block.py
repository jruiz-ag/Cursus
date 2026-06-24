class GardenError(Exception):
    def __init__(self, msg: str = 'Unknown plant error') -> None:
        Exception.__init__(self, msg)


class PlantError(GardenError):
    def __init__(self, msg: str = 'Unknown plant error') -> None:
        GardenError.__init__(self, msg)


def water_plant(plant_name: str) -> None:
    if not (plant_name == plant_name.capitalize()):
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")
    print(f"Watering {plant_name}: [OK]")


def test_watering_system() -> None:
    print("=== Garden Watering System ===")

    print("\nTesting valid plants...")
    print("Opening watering system")
    water_plant("Tomato")
    water_plant("Lettuce")
    water_plant("Carrots")
    print("Closing watering system")

    print("\nTesting invalid plants...")
    print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("lettuce")
        water_plant("carrots")
    except PlantError as ex:
        print(f"Caught PlantError: {ex}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system")


if __name__ == "__main__":
    test_watering_system()
    print("\nCleanup always happens, even with errors!")
