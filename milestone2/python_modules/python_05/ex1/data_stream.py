#!/usr/bin/env python3.10

import typing
from typing import Any
from abc import ABC, abstractmethod


TRANSLATIONS = {"NumericProcessor": "Numeric Processor",
                "TextProcessor": "Text Processor",
                "LogProcessor": "Log Processor"}


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


class DataStream():
    def __init__(self) -> None:
        self.proc_dict: dict = {}

    def register_processor(self, proc: DataProcessor) -> None:
        if type(proc).__name__ not in self.proc_dict.keys():
            self.proc_dict[type(proc).__name__] = [proc, 0]

    def process_stream(self, stream: list[typing.Any]) -> None:
        able: bool = False
        for elm in stream:
            able = False
            for name in self.proc_dict:
                try:
                    self.proc_dict[name][0].ingest(elm)
                except Exception:
                    pass
                else:
                    if isinstance(elm, list):
                        self.proc_dict[name][1] += len(elm)
                    else:
                        self.proc_dict[name][1] += 1
                    able = True
            if not able:
                print("DataStream error - ", end="")
                print(f"Can't process element in stream: {elm}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if len(self.proc_dict) == 0:
            print("No processor found, no data")
            return
        for name in self.proc_dict:
            processed: int = self.proc_dict[name][1]
            processor: int = len(self.proc_dict[name][0].data)
            print(f"{TRANSLATIONS[name]}: total {processed} items ", end="")
            print(f"processed, remaining {processor} ", end="")
            print("on processor")

    def consume(self, name: str) -> None:
        self.proc_dict[name][0].output()


def main() -> None:
    print("=== Code Nexus - Data Stream ===")

    print("\nInitialize Data Stream...")
    class_1: DataStream = DataStream()
    class_1.print_processors_stats()

    print("\nRegistering Numeric Processor")
    class_1.register_processor(NumericProcessor())

    list_1: list = ["Hello world", [3.14, -1, 2.71]]
    list_1.append([{"log_level": "WARNING",
                    "log_message": "Telnet access! Use ssh instead"},
                   {"log_level": "INFO",
                    "log_message": "User wil is connected"}])
    list_1.append(42)
    list_1.append(["Hi", "five"])
    print(f"\nSend first batch of data on stream: {list_1}")
    class_1.process_stream(list_1)
    class_1.print_processors_stats()

    print("\nRegistering other data processors")
    class_1.register_processor(TextProcessor())
    class_1.register_processor(LogProcessor())
    print("Send the same batch again")
    class_1.process_stream(list_1)
    class_1.print_processors_stats()

    print("\nConsume some elements from the data processors: ", end="")
    print("Numeric 3, Text 2, Log 1")
    class_1.consume("NumericProcessor")
    class_1.consume("NumericProcessor")
    class_1.consume("NumericProcessor")
    class_1.consume("TextProcessor")
    class_1.consume("TextProcessor")
    class_1.consume("LogProcessor")
    class_1.print_processors_stats()


if __name__ == "__main__":
    main()
