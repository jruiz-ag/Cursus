import importlib.util
import importlib.metadata
from typing import Any


def fetch_matrix_data(requests: Any) -> list[float]:
    url = "https://api.coindesk.com/v1/bpi/currentprice.json"

    try:
        response = requests.get(url, timeout=5)
        response.raise_for_status()
        data = response.json()
        rate = data["bpi"]["USD"]["rate_float"]
        return [rate]
    except Exception:
        return []


def generate(np: Any, pd: Any, requests: Any, plt: Any) -> None:
    print('Analyzing Matrix data...')

    api_data = fetch_matrix_data(requests)
    data_points = np.random.randn(1000)

    if api_data:
        data_points = data_points + (api_data[0] / 10000)

    df = pd.DataFrame(data_points, columns=['Data'])
    print('Processing 1000 data points...')

    df['Time'] = np.arange(len(df))

    print('Generating visualization...\n')
    plt.figure(figsize=(10, 6))
    plt.plot(df['Time'], df['Data'], color='green', linewidth=0.4)

    print("Analysis complete!")
    plt.savefig('matrix_analysis.png')
    print("Results saved to: matrix_analysis.png")


def validate_modules() -> bool:
    all_good: bool = True
    to_find: list[tuple[str, str]] = [("pandas", "2.1.0"),
                                      ("numpy", "1.25.0"),
                                      ("requests", "2.31.0"),
                                      ("matplotlib", "3.7.2")]
    for (module, exact_vers) in to_find:
        found = importlib.util.find_spec(module)
        if found:
            try:
                vers = importlib.metadata.version(module)
                if (vers != exact_vers):
                    raise ValueError
            except importlib.metadata.PackageNotFoundError:
                vers = "unknown version"
            except ValueError:
                print(f"[KO] {module} ({vers}) - not valid version", end="")
                print(f" must be {exact_vers}")
                all_good = False
                continue
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
        print("You need to install the required modules.")
        print(" -> With poetry: <poetry install>")
        print(" -> With pip: <pip install -r requirements.txt>.")
        print("Then try again.")
        return
    numpy: Any = importlib.import_module('numpy')
    pandas: Any = importlib.import_module('pandas')
    requests: Any = importlib.import_module('requests')
    matplotlib_pyplot: Any = importlib.import_module('matplotlib.pyplot')
    generate(numpy, pandas, requests, matplotlib_pyplot)


if __name__ == "__main__":
    main()
