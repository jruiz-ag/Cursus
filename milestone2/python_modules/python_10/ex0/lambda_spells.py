#!/usr/bin/env python3.10

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    """ Sort the list in a descending way based on the 'power' field """
    return (sorted(artifacts, key=lambda x: x['power'],  reverse=True))


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    """ Filter the list using the minimum power allowed """
    return (list(filter(lambda x: x['power'] >= min_power, mages)))


def spell_transformer(spells: list[str]) -> list[str]:
    """ Make a transform in the whole elements of the list """
    return (list(map(lambda text: "* " + text + " *", spells)))


def mage_stats(mages: list[dict]) -> dict:
    """ Extract the basic metrics of a list (max, min, mean) """
    dict_result = dict()

    dict_result['max_power'] = max(mages, key=lambda x: x['power'])['power']
    dict_result['min_power'] = min(mages, key=lambda x: x['power'])['power']

    power_levels = list(elm['power'] for elm in mages)
    dict_result['avg_power'] = round(sum(power_levels)/len(power_levels), 2)

    return (dict_result)


def output(elm: dict, flag: int = 0) -> str:
    if (flag == 0):
        return (f"{elm['name']} {elm['type']} ({elm['power']} power)")
    elif (flag == 1):
        return (f"{elm['name']} {elm['element']} ({elm['power']} power)")
    else:
        return (f"Maximum power: {elm['max_power']} -- "
                f"Minimum power: {elm['min_power']} -- "
                f"Average power: {elm['avg_power']}")


def main() -> None:
    """ Testing the differents lambda functions """

    print("\nTesting artifact sorter...")
    list_1: list[dict] = [{'name': 'Crystal', 'power': 85, 'type': 'Orb'},
                          {'name': 'Fire', 'power': 92, 'type': 'Staff'}]
    sorted_1: list[dict] = artifact_sorter(list_1)
    print(f"{output(sorted_1[0], 0)} comes before {output(sorted_1[1], 0)}")

    print("\nTesting power filter..-")
    list_2: list[dict] = [{'name': 'Mario', 'power': 61, 'element': 'Red'},
                          {'name': 'Luigi', 'power': 37, 'element': 'Green'}]
    filter_2: list[dict] = power_filter(list_2, 50)
    for elm in filter_2:
        print(f"{output(elm, 1)} overpass the minimum value")

    print("\nTesting spell transformer...")
    list_3: list[str] = ["fireball", "heal", "shield"]
    print(" ".join(spell_transformer(list_3)))

    print("\nTesting mages stats...")
    print(output(mage_stats(list_2), 2))


if __name__ == "__main__":
    main()
