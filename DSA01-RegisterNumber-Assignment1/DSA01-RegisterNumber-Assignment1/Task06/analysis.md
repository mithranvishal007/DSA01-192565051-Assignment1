# Task 6 — Control Structures and Alternative Fare Lookup

The `switch` statement selects the zone's base fare, an `if` applies the peak surcharge, and another `if` checks the minimum remaining balance. A `for` loop is appropriate for the known trip array; a range-based `for` makes iteration concise. A `while` loop is more suitable for retrying input until valid. `break` ends a switch case; `continue` can skip an invalid trip in a batch. If a `switch` receives a value with no matching case and no `default`, no case body runs, so production code should validate the zone or reject the default case.

Peak rule: `((hour >= 8 && hour < 10) || (hour >= 17 && hour < 20))`. The start times 8 and 17 are peak, while 10 and 20 are off-peak. The program tests exactly these four values.

Alternative: a `constexpr long long FARE[] = {1000, 2000, 3000}` indexed by a validated zone value replaces the switch. Both switch and array lookup are O(1) time. The table uses three fare values of storage (typically 24 bytes for three `long long` values), while a compiler may implement a dense switch as a jump table. Adding a fourth zone requires one more enum value and fare entry; a switch requires another case. The table reduces duplicated mapping code but relies on enum ordering matching table indices, so tests should cover every zone.

`fare_array.cpp` is the compact array-lookup alternative. The index must be validated before lookup in production code; the sample only uses valid enum values.
