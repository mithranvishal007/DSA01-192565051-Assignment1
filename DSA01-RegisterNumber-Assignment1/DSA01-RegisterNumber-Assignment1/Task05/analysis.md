# Task 5 — Operators, Precedence and Output Prediction

## Prediction written before execution
```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

## Actual output
The actual output matches the prediction.

## Operator-by-operator explanation
- `y * 2` is evaluated before addition, so `5 + 3 * 2 = 11`. Parentheses force `(5 + 3) * 2 = 16`.
- `x++` contributes the old value 5 and then increments x to 6. `++y` increments y from 3 to 4 and contributes 4. Thus `z = 5 + 4 = 9`; x=6 and y=4.
- `x > y` is true, so the conditional operator chooses x=6. `%` and `*` have equal precedence and associate left-to-right: `(6 % 4) * 2 = 4`.
- Integer division truncates toward zero: 10/3=3 and -10/3=-3. The remainder keeps the dividend's sign: 10%3=1 and -10%3=-1.
- The loop adds i values 0, 3, 6, 9, giving k=18.

Peak-hour expression: `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`. Parentheses improve readability; `&&` binds more tightly than `||`, so the unparenthesized form is equivalent. `x++` uses the old value; `++x` uses the incremented value. Avoid `i = i++` because it is confusing and redundant; it was undefined before C++17, while C++17 sequencing rules define it. Prefer a separate `i++` statement when incrementing is intended. For negative operands, `/` truncates toward zero and `%` is consistent with `a == (a/b)*b + a%b`.

Alternative: `bool peak[24]` gives O(1) lookup time and uses 24 bool elements (typically 24 bytes). The combined expression is also O(1) and uses no table storage; it may be preferable for only two intervals. A table is easier to maintain for many irregular schedules.

`peak_table.cpp` demonstrates the alternative lookup-table implementation. It initializes a 24-element boolean table and marks hours 8–9 and 17–19 as peak. The check is a single O(1) array lookup, at the cost of 24 bool elements (typically 24 bytes).
