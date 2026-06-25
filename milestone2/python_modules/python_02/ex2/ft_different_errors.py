#!/usr/bin/env python3.10

def garden_operations(operation_number: int) -> None:
    if (operation_number == 0):
        int("abc")
    elif (operation_number == 1):
        1/0
    elif (operation_number == 2):
        open("/non/existent/file")
    elif (operation_number == 3):
        "abc" + 1


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")

    print("Testing operation 0...")
    try:
        garden_operations(0)
    except ValueError as ex:
        print(f"Caught ValueError: {ex}")
    except ZeroDivisionError as ex:
        print(f"Caught ZeroDivisionError: {ex}")
    except FileNotFoundError as ex:
        print(f"Caught FileNotFoundError: {ex}")
    except TypeError as ex:
        print(f"Caught TypeError: {ex}")
    else:
        print("Operation completed successfully")

    print("Testing operation 1...")
    try:
        garden_operations(1)
    except ValueError as ex:
        print(f"Caught ValueError: {ex}")
    except ZeroDivisionError as ex:
        print(f"Caught ZeroDivisionError: {ex}")
    except FileNotFoundError as ex:
        print(f"Caught FileNotFoundError: {ex}")
    except TypeError as ex:
        print(f"Caught TypeError: {ex}")
    else:
        print("Operation completed successfully")

    print("Testing operation 2...")
    try:
        garden_operations(2)
    except ValueError as ex:
        print(f"Caught ValueError: {ex}")
    except ZeroDivisionError as ex:
        print(f"Caught ZeroDivisionError: {ex}")
    except FileNotFoundError as ex:
        print(f"Caught FileNotFoundError: {ex}")
    except TypeError as ex:
        print(f"Caught TypeError: {ex}")
    else:
        print("Operation completed successfully")

    print("Testing operation 3...")
    try:
        garden_operations(3)
    except ValueError as ex:
        print(f"Caught ValueError: {ex}")
    except ZeroDivisionError as ex:
        print(f"Caught ZeroDivisionError: {ex}")
    except FileNotFoundError as ex:
        print(f"Caught FileNotFoundError: {ex}")
    except TypeError as ex:
        print(f"Caught TypeError: {ex}")
    else:
        print("Operation completed successfully")

    print("Testing operation 4...")
    try:
        garden_operations(4)
    except ValueError as ex:
        print(f"Caught ValueError: {ex}")
    except ZeroDivisionError as ex:
        print(f"Caught ZeroDivisionError: {ex}")
    except FileNotFoundError as ex:
        print(f"Caught FileNotFoundError: {ex}")
    except TypeError as ex:
        print(f"Caught TypeError: {ex}")
    else:
        print("Operation completed successfully")

    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
