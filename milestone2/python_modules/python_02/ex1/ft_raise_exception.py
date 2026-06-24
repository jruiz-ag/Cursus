def input_temperature(temp_str: str) -> int:
    temp_int: int = int(temp_str)
    if (temp_int < 0):
        raise ValueError(f"{temp_int} is too cold for plants (min 0ºC)")
    elif (temp_int > 40):
        raise ValueError(f"{temp_int} is too hot for plants (max 40ºC)")
    return (int(temp_str))


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===")

    input_1: str = "25"
    print(f"\nInput data is {input_1}")
    valor_1: int = input_temperature(input_1)
    print(f"Temperature is now {valor_1}ºC")

    input_2: str = "abc"
    print(f"\nInput data is {input_2}")
    try:
        valor_2: int = input_temperature(input_2)
    except ValueError as ex:
        print(f"Caught input_temperature error: {ex}")
    else:
        print(f"Se imprimiría {valor_2} si se hubiera convertido bien")

    input_3: str = "100"
    print(f"\nInput data is {input_3}")
    try:
        valor_3: int = input_temperature(input_3)
    except ValueError as ex:
        print(f"Caught input_temperature error: {ex}")
    else:
        print(f"Se imprimiría {valor_3} si se hubiera convertido bien")

    input_4: str = "-50"
    print(f"\nInput data is {input_4}")
    try:
        valor_4: int = input_temperature(input_4)
    except ValueError as ex:
        print(f"Caught input_temperature error: {ex}")
    else:
        print(f"Se imprimiría {valor_4} si se hubiera convertido bien")
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
