# Task 6 — Pseudocode and Control Structures

```text
ALGORITHM CalculateFare(zone, peak)
    CASE zone OF
        Inner: baseFare <- 1000
        Middle: baseFare <- 2000
        Outer: baseFare <- 3000
        OTHERWISE: reject invalid zone
    END CASE
    IF peak THEN
        baseFare <- baseFare + (baseFare * 20 DIV 100)
    END IF
    RETURN baseFare
END ALGORITHM

ALGORITHM CanTravel(balance, fare)
    RETURN (balance - fare >= 5000)
END ALGORITHM
```

The switch is readable for a small closed set of zones. `if` is suitable for surcharge and balance checks; `?:` is suitable only for a short expression. A counted `for` loop fits a known list/array of trips; range-based `for` is clean when iterating over a container; `while` is appropriate when input continues until a sentinel or until valid input is received. `break` exits a switch case or stops a search; `continue` skips an invalid journey when processing a batch. A switch without a matching case and without `default` does not execute a case; for safety, validate enum values or add a default rejection.

Boundary rule: hour 8 and 17 are peak; hour 10 and 20 are off-peak. The included program prints these boundary results after the required sample journeys.
