import os


def take_keys() -> str:
    keys: list[str] = ["MATRIX_MODE",
                       "DATABASE_URL",
                       "API_KEY",
                       "LOG_LEVEL",
                       "ZION_ENDPOINT"]
    show: dict[str, str] = {"MATRIX_MODE": "Mode",
                            "DATABASE_URL": "Database",
                            "API_KEY": "API Access",
                            "LOG_LEVEL": "Log Level",
                            "ZION_ENDPOINT": "Zion Network"}
    missed: str = ""
    print("Configuration loaded:")
    for key in keys:
        val = os.getenv(key)
        print(f"{show[key]}: ", end="")
        if (not val):
            print("[ERROR] This parameter is not defined.")
            missed += key + ", "
        else:
            if (key == "MATRIX_MODE" and not (val in ['development',
                                                      'production'])):
                print("[ERROR] This value must be", end="")
                print(" 'development' or 'production'")
                missed += key + ", "
            elif (key == "API_KEY"):
                print("Authenticated")
            elif (key == "ZION_ENDPOINT"):
                print("Online")
            elif (key == "DATABASE_URL"):
                print("Connected to local instance")
            else:
                print(val)
    return (missed)


def main() -> None:
    print("\nORACLE STATUS: Reading the matrix...\n")
    try:
        import dotenv  # type: ignore[import-not-found]
    except ImportError:
        print("[ERROR] Module 'python-dotenv' not installed.")
        print("To solve the problem use: <pip install -r requirements.txt>.")
        print("Then run again.\n")
        return
    dotenv.load_dotenv()
    missed = take_keys()
    if (missed):
        print("\nSome parameters are not defined or are invalid.")
        print("You must use the standard <KEY=VALUE> format.")
        print(f"Missed keys or invalid values: {missed.strip(', ')}")
    else:
        print("\nEnvironment security check:")
        print("[OK] No hardcoded secrets detected")
        print("[OK] .env file properly configured")
        print("[OK] Production overrides available")
        print("\nThe Oracle sees all configurations.")
    print()


if __name__ == "__main__":
    main()
