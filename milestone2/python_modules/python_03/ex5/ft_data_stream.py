#!/usr/bin/env python3.10

import typing
import random


def gen_event() -> typing.Generator:
    players: list = ["bob", "alice", "dylan", "charlie"]
    actions: list = ["run", "eat", "sleep", "grab", "move",
                     "climb", "swim", "release"]
    while True:
        yield (random.choice(players), random.choice(actions))


def consume_event(events: list) -> typing.Generator:
    while True:
        if len(events) <= 0:
            break
        else:
            event: tuple = random.choice(events)
            events.remove(event)
            yield event


def main() -> None:
    init: typing.Generator = gen_event()

    print("=== Game Data Stream Processor ===")
    for i in range(1000):
        chain: tuple = next(init)
        print(f"Event {i}: Player {chain[0]} did action {chain[1]}")

    events: list = []
    for i in range(10):
        chain = next(init)
        events.append(chain)
    print(f"Built list of 10 events: {events}")

    init = consume_event(events)
    for event in init:
        print(f"Got event from list: {event}")
        print(f"Remains in list: {events}")


if __name__ == "__main__":
    main()
