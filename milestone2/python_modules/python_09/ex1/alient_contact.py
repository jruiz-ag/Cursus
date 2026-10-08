#!/usr/bin/env python3.10

from pydantic import BaseModel, Field  # type: ignore[import-not-found]
from pydantic import model_validator  # type: ignore[import-not-found]
from pydantic import ValidationError  # type: ignore[import-not-found]
from enum import Enum
from datetime import datetime


class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(...,
                            min_length=5,
                            max_length=15,
                            description="ID of the specific communication")

    timestamp: datetime = Field(...,
                                description="When took place"
                                            "the communication")

    location: str = Field(...,
                          min_length=3,
                          max_length=100,
                          description="Where took place"
                                      "the communication")

    contact_type: ContactType = Field(...,
                                      description="Specific type of the"
                                                  "contact")

    signal_strength: float = Field(...,
                                   ge=0.0,
                                   le=10.0,
                                   description="Strength of a"
                                               "specific contact")

    duration_minutes: int = Field(...,
                                  ge=1,
                                  le=1440,
                                  description="Duration in minutes"
                                              "of the contact")

    witness_count: int = Field(...,
                               ge=1,
                               le=100,
                               description="How many people witness"
                                           "the contact")

    message_received: str = Field(default="",
                                  max_length=500,
                                  description="Which message was received")

    is_verified: bool = Field(default=True,
                              description="Control the validate"
                                          "of the contact")

    @model_validator(mode='after')
    def rules(self):
        if not (self.contact_id.startswith('AC')):
            raise ValueError("Contact ID must start with 'AC'.")
        if (self.contact_type == ContactType.PHYSICAL
           and not (self.is_verified)):
            raise ValueError("Physical contact must be verified.")
        if (self.contact_type == ContactType.TELEPATHIC
           and (self.witness_count < 3)):
            raise ValueError("Telepathic contact must have at least"
                             " 3 witnesses.")
        if (self.signal_strength > 7 and not (self.message_received)):
            raise ValueError("Strong signals (> 7) must have messages.")
        return self


def show(contact: AlienContact) -> None:
    if contact.is_verified:
        print("Valid contact report:")
    else:
        print("Unvalid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    if contact.message_received:
        print(f"Message: '{contact.message_received}'")
    print()


def valid_1() -> None:
    print("=" * 38)
    contact = AlienContact(contact_id="AC_2024_001",
                           timestamp=datetime(2025, 9, 30),
                           location="Area 51, Nevada",
                           contact_type=ContactType.RADIO,
                           signal_strength=8.5,
                           duration_minutes=45,
                           witness_count=5,
                           message_received="Greetings from Zera"
                                            " Reticuli")
    show(contact)


def error_1() -> None:
    """Invalid because of not starting contact_id with 'AC'"""
    print("=" * 38)
    try:
        contact = AlienContact(contact_id="BC_2024_001",
                               timestamp=datetime(2025, 9, 30),
                               location="Area 51, Nevada",
                               contact_type=ContactType.RADIO,
                               signal_strength=8.5,
                               duration_minutes=45,
                               witness_count=5,
                               message_received="Greetings from Zera"
                                                " Reticuli")
    except ValidationError as ex:
        print(ex.errors()[0]["msg"])
    except ValueError as ex:
        print(ex)
    else:
        show(contact)
    print("=" * 38, "\n")


def valid_2() -> None:
    print("=" * 38)
    contact = AlienContact(contact_id="AC_2024_001",
                           timestamp=datetime(2025, 9, 30),
                           location="Area 51, Nevada",
                           contact_type=ContactType.PHYSICAL,
                           signal_strength=8.5,
                           duration_minutes=45,
                           witness_count=5,
                           message_received="Greetings from Zera"
                                            " Reticuli",
                           is_verified=True)
    show(contact)


def error_2() -> None:
    """Invalid because of being a physical contact but not verified"""
    print("=" * 38)
    try:
        contact = AlienContact(contact_id="AC_2024_001",
                               timestamp=datetime(2025, 9, 30),
                               location="Area 51, Nevada",
                               contact_type=ContactType.PHYSICAL,
                               signal_strength=8.5,
                               duration_minutes=45,
                               witness_count=5,
                               message_received="Greetings from Zera"
                                                " Reticuli",
                               is_verified=False)
    except ValidationError as ex:
        print(ex.errors()[0]["msg"])
    except ValueError as ex:
        print(ex)
    else:
        show(contact)
    print("=" * 38, "\n")


def valid_3() -> None:
    print("=" * 38)
    contact = AlienContact(contact_id="AC_2024_001",
                           timestamp=datetime(2025, 9, 30),
                           location="Area 51, Nevada",
                           contact_type=ContactType.TELEPATHIC,
                           signal_strength=8.5,
                           duration_minutes=45,
                           witness_count=3,
                           message_received="Greetings from Zera"
                                            " Reticuli")
    show(contact)


def error_3() -> None:
    """Invalid because is a telepathic contact but have less of 3 witness"""
    print("=" * 38)
    try:
        contact = AlienContact(contact_id="AC_2024_001",
                               timestamp=datetime(2025, 9, 30),
                               location="Area 51, Nevada",
                               contact_type=ContactType.TELEPATHIC,
                               signal_strength=8.5,
                               duration_minutes=45,
                               witness_count=2,
                               message_received="Greetings from Zera"
                                                " Reticuli")
    except ValidationError as ex:
        print(ex.errors()[0]["msg"])
    except ValueError as ex:
        print(ex)
    else:
        show(contact)
    print("=" * 38, "\n")


def valid_4() -> None:
    print("=" * 38)
    contact = AlienContact(contact_id="AC_2024_001",
                           timestamp=datetime(2025, 9, 30),
                           location="Area 51, Nevada",
                           contact_type=ContactType.TELEPATHIC,
                           signal_strength=8.5,
                           duration_minutes=45,
                           witness_count=5,
                           message_received="A valid communication")
    show(contact)


def error_4() -> None:
    """Invalid because of being a strong signal (> 7) without message"""
    print("=" * 38)
    try:
        contact = AlienContact(contact_id="AC_2024_001",
                               timestamp=datetime(2025, 9, 30),
                               location="Area 51, Nevada",
                               contact_type=ContactType.TELEPATHIC,
                               signal_strength=8.5,
                               duration_minutes=45,
                               witness_count=5)
    except ValidationError as ex:
        print(ex.errors()[0]["msg"])
    except ValueError as ex:
        print(ex)
    else:
        show(contact)
    print("=" * 38, "\n")


def main() -> None:
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
