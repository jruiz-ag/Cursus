import sys
import os
import importlib.metadata
import importlib.util


def error(exact_vers: str, vers: str) -> None:
    print(f"[ERROR] python-dotenv", end="")
    if not vers:
        print(" (Not installed).")
    else:
        print(f" ({vers}) - not valid version required {exact_vers}")
    print("To solve the problem use: <pip install -r requirements.txt>.\n")


def take_keys() -> str:
    all_good: bool = True
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
                print("Connected")
            else:
                print(val)
    return (missed)


def main() -> None:
    print("\nORACLE STATUS: Reading the matrix...\n")
    if not (os.path.exists(".env")):
        print("[ERROR] No valid file '.env' to load configuration.\n")
        return
    dotenv = importlib.util.find_spec("dotenv")
    exact_vers: str = "1.2.3"
    if dotenv:
        try:
            vers = importlib.metadata.version("python-dotenv")
            if (vers != exact_vers):
                error(exact_vers, vers)
                return
        except importlib.metadata.PackageNotFoundError:
            error(exact_vers, "")
            return
    if not(dotenv):
        error(exact_vers, "")
        return 
    dotenv = importlib.import_module("dotenv")
    dotenv.load_dotenv()
    missed = take_keys()
    if (missed):
        print("\nSome parameters are not defined or are invalid.")
        print(f"You must use the standard <KEY=VALUE> format.")
        print(f"Missed keys or invalid values: {missed.strip(', ')}")
    print()

if __name__ == "__main__":
    main()