#!/usr/bin/env python3.10


def secure_archive(file: str, action: str = "r",
                   content: str = "") -> tuple[bool, str]:
    try:
        if (action == "write"):
            action = "w"
        elif (action == "read"):
            action = "r"
        with open(file, action) as fich:
            if (action == "r"):
                text: str = fich.read()
                return (True, text)
            elif (action == "w"):
                fich.write(content)
                return (True, "Content successfully written to file")
            else:
                return (False, "Not valid action")
    except (FileNotFoundError, PermissionError) as ex:
        return (False, f"{ex}")


def main() -> None:
    print("=== Cyber Archives Security ===")

    print("\nUsing 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/non/existing/file", "r"))

    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/master.passwd", "r"))

    print("\nUsing 'secure_archive' to read from a regular file:")
    text: tuple[bool, str] = secure_archive("ancient_fragment.txt", "r")
    print(text)

    print("\nUsing 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_fragment.txt", "w", text[1]))


if __name__ == "__main__":
    main()
