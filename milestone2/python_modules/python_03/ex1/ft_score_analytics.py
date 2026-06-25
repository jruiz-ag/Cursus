#!/usr/bin/env python3.10

import sys


def analysis(list_scores: list[int]) -> None:
    print(f"Total players: {len(list_scores)}")
    print(f"Total score: {sum(list_scores)}")
    print(f"Average score: {sum(list_scores) / len(list_scores)}")
    print(f"High score: {max(list_scores)}")
    print(f"Low score: {min(list_scores)}")
    print(f"Range score: {max(list_scores) - min(list_scores)}")


def main() -> None:
    error_msg: str = "No scores provided. Usage: python3"
    error_msg += " ft_score_analytics.py <score1> <score2> ..."
    list_scores: list[int] = []

    print("=== Player Score Analytics ===")
    if (len(sys.argv)) <= 1:
        print(error_msg)
    else:
        for num in sys.argv[1:]:
            try:
                int(num)
            except ValueError:
                print(f"Invalid parameter: '{num}'")
            else:
                list_scores.append(int(num))
        if (len(list_scores)) == 0:
            print(error_msg)
        else:
            print(f"Scores processed: {list_scores}")
            analysis(list_scores)


if __name__ == "__main__":
    main()
