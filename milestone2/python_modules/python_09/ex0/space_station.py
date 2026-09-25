from pydantic import BaseModel, Field  # type: ignore[import-not-found]
from pydantic import ValidationError  # type: ignore[import-not-found]
from datetime import date


class SpaceStation(BaseModel):
    station_id: str = Field(...,
                            min_length=3,
                            max_length=10,
                            description="Unique ID for this station")

    name: str = Field(...,
                      min_length=1,
                      max_length=50,
                      description="Common name given to this station")

    crew_size: int = Field(...,
                           ge=1,
                           le=20,
                           description="Amount of people inside this station")

    power_level: float = Field(...,
                               ge=0.0,
                               le=100.0,
                               description="Amount of power in this station")

    oxygen_level: float = Field(...,
                                ge=0.0,
                                le=100.0,
                                description="Level of oxygen in this station")

    last_maintenance: date = Field(...,
                                   description="Date of the last maintenance")

    is_operational: bool = Field(default=True,
                                 description="Indicate the valid state")

    notes: str = Field(default="",
                       max_length=200)


def show_station(station: SpaceStation) -> None:
    print(f"ID: {station.station_id}")
    print(f"Name: {station.name}")
    print(f"Crew: {station.crew_size} people")
    print(f"Power: {station.power_level}%")
    print(f"Oxygen: {station.oxygen_level}%")
    print(f"Status: {'O' if station.is_operational else 'Not o'}perational")
    if (station.notes):
        print(f"Notes: {station.notes}")
    print()


def first_valid() -> None:
    print("=" * 35)
    print("Valid station created:")
    station_1 = SpaceStation(station_id="ISS001",
                             name="International Space Station",
                             crew_size=6,
                             power_level=85.5,
                             oxygen_level=92.3,
                             last_maintenance=date(2026, 9, 25))
    show_station(station_1)
    print("=" * 35)


def first_error() -> None:
    print("Expected validation error:")
    try:
        SpaceStation(station_id="ISS001",
                     name="International Space Station",
                     crew_size=21,
                     power_level=85.5,
                     oxygen_level=92.3,
                     last_maintenance=date(2026, 9, 25),
                     is_operational=False)
    except ValidationError as ex:
        print(ex.errors()[0]["msg"])


def second_valid() -> None:
    print("=" * 35)
    print("Second valid station created:")
    station_2 = SpaceStation(station_id="ISS002",
                             name="European Space Station",
                             crew_size=9,
                             power_level="10.1",
                             oxygen_level=1.01,
                             last_maintenance=date(2026, 1, 25),
                             is_operational=False,
                             notes="This station is deprecated")
    show_station(station_2)
    print("=" * 35)


def second_error() -> None:
    print("Expected validation error:")
    try:
        SpaceStation(station_id=2,
                     name="International Space Station",
                     crew_size=19,
                     power_level=85,
                     oxygen_level=92.3,
                     last_maintenance=date(2026, 9, 25),
                     is_operational=True)
    except ValidationError as ex:
        print(ex.errors()[0]["msg"])


def main() -> None:
    first_valid()
    first_error()
    second_valid()
    second_error()


if __name__ == "__main__":
    main()
