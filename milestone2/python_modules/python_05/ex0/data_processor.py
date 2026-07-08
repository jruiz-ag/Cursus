#!/usr/bin/env python3.10

from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.count: int = 0
        self.data: list = list()

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        oldest: Any = self.data[0]
        self.count += 1
        del self.data[0]
        return (self.count - 1, oldest)


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: Any) -> bool:
        try:
            if (data != int(data)) and (data != float(data)):
                return (False)
        except ValueError:
            return False
        else:
            return True

    def ingest(self, data: Any) -> None:
        if (isinstance(data, list)):
            for subdata in data:
                if (self.validate(subdata) is False):
                    raise Exception("Improper numeric data")
                self.data.append(str(subdata))
        else:
            if (self.validate(data) is False):
                raise Exception("Improper numeric data")
            self.data.append(str(data))


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: Any) -> bool:
        try:
            if (data != str(data)):
                return (False)
        except ValueError:
            return False
        else:
            return True

    def ingest(self, data: Any) -> None:
        if (isinstance(data, list)):
            for subdata in data:
                if (self.validate(subdata) is False):
                    raise Exception("Improper textual data")
                self.data.append(str(subdata))
        else:
            if (self.validate(data) is False):
                raise Exception("Improper textual data")
            self.data.append(str(data))


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: Any) -> bool:
        try:
            if (data != dict(data)):
                return (False)
        except ValueError:
            return False
        else:
            return True

    def ingest(self, data: Any) -> None:
        if (isinstance(data, list)):
            for subdata in data:
                if (self.validate(subdata) is False):
                    raise Exception("Improper textual data")
                text: str = f"{subdata["log_level"]}: {subdata["log_message"]}"
                self.data.append(text)
        else:
            if (self.validate(data) is False):
                raise Exception("Improper dictionary data")
            self.data.append(f"{data["log_level"]}: {data["log_message"]}")


def stage_1() -> None:
    num_processor: NumericProcessor = NumericProcessor()
    print("\nTesting Numeric Processor...")

    print(" Trying to validate input '42': ", end="")
    print(num_processor.validate(42))
    print(" Trying to validate input 'Hello': ", end="")
    print(num_processor.validate("Hello"))

    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_processor.ingest("foo")
    except Exception as ex:
        print(f" Got exception: {ex}")
    else:
        print(" Correctly ingested")

    list_1: list = [1, 2, 3, 4, 5]
    print(f" Processing data: {list_1}")
    num_processor.ingest(list_1)
    print(" Extracting 3 values...")
    for _ in range(3):
        tuple_1: tuple = num_processor.output()
        print(f" Numeric value {tuple_1[0]}: {tuple_1[1]}")


def stage_2() -> None:
    text_processor: TextProcessor = TextProcessor()
    print("\nTesting Text Processor...")

    print(" Trying to validate input '42': ", end="")
    print(text_processor.validate(42))

    list_1: list = ["Hello", "Nexus", "World"]
    print(f" Processing data: {list_1}")
    text_processor.ingest(list_1)
    print(" Extracting 1 value...")
    tuple_1: tuple = text_processor.output()
    print(f" Text value {tuple_1[0]}: {tuple_1[1]}")


def stage_3() -> None:
    log_processor: LogProcessor = LogProcessor()
    print("\nTesting Log Processor...")

    print(" Trying to validate input 'Hello': ", end="")
    print(log_processor.validate("Hello"))

    list_1: list = [{"log_level": "NOTICE",
                     "log_message": "Connection to server"},
                    {"log_level": "ERROR",
                     "log_message": "Unauthorized access!!"}]
    print(f" Processing data: {list_1}")
    log_processor.ingest(list_1)
    for _ in range(2):
        tuple_1: tuple = log_processor.output()
        print(f" Log entry {tuple_1[0]}: {tuple_1[1]}")


def main() -> None:
    print("=== Code Nexus - Data Processor ===")

    stage_1()
    stage_2()
    stage_3()


if __name__ == "__main__":
    main()
