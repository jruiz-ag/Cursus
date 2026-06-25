#!/usr/bin/env python3.10

def input_temperature(temp_str: str) -> int:
    return (int(temp_str))


def test_temperature() -> None:
    print("=== Garden Temperature ===")

    input_1: str = "25"
    print(f"\nInput data is '{input_1}'")
    valor_1: int = input_temperature("25")
    print(f"Temperature is now {valor_1}ºC")

    input_2: str = "abc"
    print(f"\nInput data is '{input_2}'")
    try:
        valor_2: int = input_temperature("abc")
    except ValueError as ex:
        print(f"Caught input_temperature error: {ex}")
    else:
        print(f"Se imprimiría {valor_2} si se hubiera convertido bien")
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
