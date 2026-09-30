from pydantic import BaseModel, Field
from enum import Enum
from datetime import datetime


class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPHATIC = "telepathic"


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

    message_received: str = Field(...,
                                  max_length=500,
                                  description="Which message was received")

    is_verified: bool = Field(default=True,
                              description="Control the validate"
                                          "of the contact")


def show(contact: AlienContact) -> None:
    if contact.is_verified:
        print("Valid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    print(f"Message: '{contact.message_received}'")


def main() -> None:
    print("=" * 38)

    contact_1 = AlienContact(contact_id="AC_2024_001",
                             timestamp=datetime(2025, 9, 30),
                             location="Area 51, Nevada",
                             contact_type=ContactType.RADIO,
                             signal_strength=8.5,
                             duration_minutes=45,
                             witness_count=5,
                             message_received="Greetings from Zera Reticuli")
    show(contact_1)


if __name__ == "__main__":
    main()
