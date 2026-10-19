#!/usr/bin/env python3.10

from enum import Enum
from pydantic import BaseModel, Field  # type: ignore[import-not-found]
from pydantic import ValidationError  # type: ignore[import-not-found]
from pydantic import model_validator  # type: ignore[import-not-found]
from datetime import datetime  # type: ignore[import-not-found]


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(...,
                           min_length=3,
                           max_length=10,
                           description="An ID which identifies each member")

    name: str = Field(...,
                      min_length=2,
                      max_length=50,
                      description="The common name of each member")

    rank: Rank = Field(...,
                       description="Rank which defines the"
                                   "role of each member")

    age: int = Field(...,
                     ge=18,
                     le=80,
                     description="The age of each member")

    specialization: str = Field(...,
                                min_length=3,
                                max_length=30,
                                description="The area where they"
                                            "are specialized")

    years_experience: int = Field(...,
                                  ge=0,
                                  le=50,
                                  description="Experience inside this work")

    is_active: bool = Field(default=True,
                            description="Represent the availability"
                                        "of this member")


class SpaceMission(BaseModel):
    mission_id: str = Field(...,
                            min_length=5,
                            max_length=15,
                            description="The unique ID of this mission")

    mission_name: str = Field(...,
                              min_length=3,
                              max_length=100,
                              description="The common name of this mission")

    destination: str = Field(...,
                             min_length=3,
                             max_length=50,
                             description="Identify the destination to reach")

    launch_date: datetime = Field(...,
                                  description="The moment when the launch"
                                              "took place")

    duration_days: int = Field(...,
                               ge=1,
                               le=3650,
                               description="The estimate duration"
                                           "of the mission")

    crew: list[CrewMember] = Field(...,
                                   min_length=1,
                                   max_length=12,
                                   description="The list of members inside"
                                               "this mission")

    mission_status: str = Field(default="planned",
                                description="The actual status"
                                            "of the mission")

    budget_millions: float = Field(...,
                                   ge=1.0,
                                   le=10000.0,
                                   description="The budget destinates to"
                                               "this mission in millions")

    @model_validator(mode='after')
    def validate_mission(self) -> 'SpaceMission':

        if not self.mission_id.startswith('M'):
            raise ValueError("Mission ID must start with 'M'")

        captains = [member.rank == Rank.CAPTAIN for member in self.crew]
        commanders = [member.rank == Rank.COMMANDER for member in self.crew]
        if not (any(captains) or any(commanders)):
            raise ValueError("Mission must have at least one "
                             "Commander or Captain")

        if (self.duration_days > 365):
            experienced_crew = [member for member in self.crew
                                if member.years_experience >= 5]
            if (len(experienced_crew)/len(self.crew) < 0.5):
                raise ValueError("Long missions (> 365 days) need 50% "
                                 "experienced crew (5+ years)")

        active_members = [member.is_active for member in self.crew]
        if not (all(active_members)):
            raise ValueError("All crew members must be active")

        return self


def show(mission: SpaceMission) -> None:
    print("=" * 41)
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:
        print(f"- {member.name} ({member.rank.value}) - "
              f"{member.specialization}")
    print()


def valid_1() -> None:
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.COMMANDER,
                         age=21,
                         specialization="Mission Command",
                         years_experience=6)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=9)

    mission = SpaceMission(mission_id="M2024_MARS",
                           mission_name="Mars Colony Establishment",
                           destination="Mars",
                           launch_date=datetime(2026, 10, 20),
                           duration_days=900,
                           crew=[member1, member2, member3],
                           budget_millions=2500)

    show(mission)


def error_1() -> None:
    print("=" * 41)
    print("Expected validation error:")
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.CADET,
                         age=21,
                         specialization="Mission Command",
                         years_experience=6)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=9)

    try:
        mission = SpaceMission(mission_id="M2024_MARS",
                               mission_name="Mars Colony Establishment",
                               destination="Mars",
                               launch_date=datetime(2026, 10, 20),
                               duration_days=900,
                               crew=[member1, member2, member3],
                               budget_millions=2500)
    except ValidationError as ex:
        print(ex.errors()[0].get("ctx", {}).get("error"))
    else:
        show(mission)


def valid_2() -> None:
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.COMMANDER,
                         age=21,
                         specialization="Mission Command",
                         years_experience=6)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=9)

    mission = SpaceMission(mission_id="M2024_MARS",
                           mission_name="Mars Colony Establishment",
                           destination="Mars",
                           launch_date=datetime(2026, 10, 20),
                           duration_days=900,
                           crew=[member1, member2, member3],
                           budget_millions=2500)

    show(mission)


def error_2() -> None:
    print("=" * 41)
    print("Expected validation error:")
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.COMMANDER,
                         age=21,
                         specialization="Mission Command",
                         years_experience=6)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=9,
                         is_active=False)

    try:
        mission = SpaceMission(mission_id="M2024_MARS",
                               mission_name="Mars Colony Establishment",
                               destination="Mars",
                               launch_date=datetime(2026, 10, 20),
                               duration_days=900,
                               crew=[member1, member2, member3],
                               budget_millions=2500)
    except ValidationError as ex:
        print(ex.errors()[0].get("ctx", {}).get("error"))
    else:
        show(mission)


def valid_3() -> None:
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.COMMANDER,
                         age=21,
                         specialization="Mission Command",
                         years_experience=6)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=9)

    mission = SpaceMission(mission_id="M2024_MARS",
                           mission_name="Mars Colony Establishment",
                           destination="Mars",
                           launch_date=datetime(2026, 10, 20),
                           duration_days=900,
                           crew=[member1, member2, member3],
                           budget_millions=2500)

    show(mission)


def error_3() -> None:
    print("=" * 41)
    print("Expected validation error:")
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.COMMANDER,
                         age=21,
                         specialization="Mission Command",
                         years_experience=4)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=2)

    try:
        mission = SpaceMission(mission_id="M2024_MARS",
                               mission_name="Mars Colony Establishment",
                               destination="Mars",
                               launch_date=datetime(2026, 10, 20),
                               duration_days=900,
                               crew=[member1, member2, member3],
                               budget_millions=2500)
    except ValidationError as ex:
        print(ex.errors()[0].get("ctx", {}).get("error"))
    else:
        show(mission)


def valid_4() -> None:
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.COMMANDER,
                         age=21,
                         specialization="Mission Command",
                         years_experience=6)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=9)

    mission = SpaceMission(mission_id="M2024_MARS",
                           mission_name="Mars Colony Establishment",
                           destination="Mars",
                           launch_date=datetime(2026, 10, 20),
                           duration_days=900,
                           crew=[member1, member2, member3],
                           budget_millions=2500)

    show(mission)


def error_4() -> None:
    print("=" * 41)
    print("Expected validation error:")
    member1 = CrewMember(member_id="MEM-1",
                         name="Sarah Connor",
                         rank=Rank.COMMANDER,
                         age=21,
                         specialization="Mission Command",
                         years_experience=4)

    member2 = CrewMember(member_id="MEM-2",
                         name="John Smith",
                         rank=Rank.LIEUTENANT,
                         age=40,
                         specialization="Navigation",
                         years_experience=11)

    member3 = CrewMember(member_id="MEM-3",
                         name="Alice Johnson",
                         rank=Rank.OFFICER,
                         age=35,
                         specialization="Engineering",
                         years_experience=2)

    try:
        mission = SpaceMission(mission_id="S2024_MARS",
                               mission_name="Mars Colony Establishment",
                               destination="Mars",
                               launch_date=datetime(2026, 10, 20),
                               duration_days=900,
                               crew=[member1, member2, member3],
                               budget_millions=2500)
    except ValidationError as ex:
        print(ex.errors()[0].get("ctx", {}).get("error"))
    else:
        show(mission)
    print("=" * 41)


def main() -> None:
    print("Space Mission Crew Validation")
    valid_1()
    error_1()
    valid_2()
    error_2()
    valid_3()
    error_3()
    valid_4()
    error_4()


if __name__ == "__main__":
    main()
