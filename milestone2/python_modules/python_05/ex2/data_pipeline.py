#!/usr/bin/env python3.10

import typing
from typing import Any
from abc import ABC, abstractmethod


TRANSLATIONS = {"NumericProcessor": "Numeric Processor",
                "TextProcessor": "Text Processor",
                "LogProcessor": "Log Processor"}


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class CSVPlugin(ExportPlugin):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")
        for pos, elm in enumerate(data):
            print(elm[1], end="")
            if (pos < (len(data) - 1)):
                print(end=",")
        print()


class JSONPlugin(ExportPlugin):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")
        print(end="{")
        for pos, elm in enumerate(data):
            print(f'"item_{elm[0]}": "{elm[1]}"', end="")
            if (pos < (len(data) - 1)):
                print(end=", ")
        print("}")


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
        if (len(self.data)) == 0:
            return (-1, "")
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

    def consume(self, name: str) -> tuple:
        return (self.proc_dict[name][0].output())

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        output: list = []
        for name in self.proc_dict:
            output.clear()
            for _ in range(nb):
                data: tuple = self.consume(name)
                if (data[0] != -1):
                    output.append(data)
            plugin.process_output(output)


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")

    print("\nInitialize Data Stream...\n")
    class_1: DataStream = DataStream()
    class_1.print_processors_stats()

    print("\nRegistering Processors")
    class_1.register_processor(NumericProcessor())
    class_1.register_processor(TextProcessor())
    class_1.register_processor(LogProcessor())

    list_1: list = ["Hello world", [3.14, -1, 2.71]]
    list_1.append([{"log_level": "WARNING",
                    "log_message": "Telnet access! Use ssh instead"},
                   {"log_level": "INFO",
                    "log_message": "User wil is connected"}])
    list_1.append(42)
    list_1.append(["Hi", "five"])
    print(f"\nSend first batch of data on stream: {list_1}\n")
    class_1.process_stream(list_1)
    class_1.print_processors_stats()

    print("\nSend 3 processed data from each processor to a CSV plugin:")
    class_1.output_pipeline(3, CSVPlugin())

    print()
    class_1.print_processors_stats()

    list_2: list = [21, ["I love AI", "LLMs are wonderful", "Stay healthy"],
                    [{"log_level": "ERROR", "log_message": "500 server crash"},
                     {"log_level": "NOTICE",
                      "log_message": "Certificate expires in 10 days"}],
                    [32, 42, 64, 84, 128, 168], "World hello"]

    print(f"\nSend another batch of data: {list_2}\n")
    class_1.process_stream(list_2)
    class_1.print_processors_stats()

    print("\nSend 5 processed data from each processor to a JSON plugin:")
    class_1.output_pipeline(5, JSONPlugin())

    print()
    class_1.print_processors_stats()


if __name__ == "__main__":
    main()
