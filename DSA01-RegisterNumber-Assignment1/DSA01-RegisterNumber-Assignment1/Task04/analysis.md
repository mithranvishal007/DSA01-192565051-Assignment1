# Task 4 — Implicit Conversions and Output Prediction

## Prediction written before execution
```text
3 3.5
C 68
1 true
s >= u
```

## Actual output after compilation and execution
The actual output is the same as the prediction above.

## Explanation
1. `a / b` uses two `int` operands, so integer division yields 3 before conversion to `double`. The explicit cast makes the second division floating-point and yields 3.5.
2. `'A' + 2` promotes the character to `int`, adds 2, then converts the result to `char` (`C` on the usual ASCII-compatible execution character set). In `ch + 1`, `ch` is promoted to `int`, producing 68.
3. `bool flag = 5` converts nonzero integer 5 to `true`. `bool` prints as `1` by default; after `std::boolalpha`, it prints `true`.
4. In `s < u`, the signed `int` `s` is converted to unsigned because of the usual arithmetic conversions. `-1` becomes a large unsigned value, so the comparison is false and the conditional expression prints `s >= u`.

Alternative: use explicit `static_cast<double>` for intentional floating-point division and brace initialization for values where narrowing must be rejected. Explicit casts do not materially change runtime complexity or storage, but they make conversion intent visible. Brace initialization such as `int x{3.7};` is ill-formed and catches narrowing at compile time. Avoid comparing signed and unsigned values without validating their ranges.

The companion `explicit_conversions.cpp` demonstrates explicit casts. `static_cast<double>(a) / b` makes the numerator floating-point before division; `static_cast<double>(a / b)` intentionally preserves integer division first, so it prints 3.0 rather than 3.5. Brace initialization (`int x{3.7};`) is rejected at compile time because it narrows a double to int.
