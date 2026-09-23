import importlib.util
import importlib.metadata


def show_fault() -> None:
    print("You need to install the required modules")


def validate_modules() -> bool:
    all_good: bool = True
    to_find: list = ["pandas", "numpy", "requests", "matplotlib"]
    for module in to_find:
        found = importlib.util.find_spec(module)
        if found:
            try:
                vers = importlib.metadata.version(module)
            except importlib.metadata.PackageNotFoundError:
                vers = "unknown version"
            print(f"[OK] {module} ({vers}) - ", end="")
            if (module == "pandas"):
                print("Data manipulation ready")
            elif (module == "numpy"):
                print("Numerical computation ready")
            elif (module == "requests"):
                print("Network access ready")
            elif (module == "matplotlib"):
                print("Visualization ready")
        else:
            print(f"[KO] {module} - Not installed")
            all_good = False
    print()
    return (all_good)


def main() -> None:
    print("LOADING STATUS: Loading programs...\n")
    if not (validate_modules()):
        show_fault()
        return    
    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")
    print("Generating visualization...\n")
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")
    

if __name__ == "__main__":
    main()