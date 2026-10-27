# Task 3 — Data Types and Compatibility

| Value | Recommended type | Reason |
|---|---|---|
| Fare/balance | `long long` paise | exact integer arithmetic and large totals |
| Hour | `int` | values 0–23 |
| Zone | `enum class Zone` | readable, type-safe values |
| Journey count | `long long` | network-scale counts and totals |
| Valid/peak status | `bool` | true/false state |
| Single character | `char` | character data |
| Approximate measurement only | `double` | not for settlement money |
| Inferred local type | `auto` | only when the inferred type is clear |

On the supplied g++/Linux environment, the program prints `sizeof` values at runtime; typical sizes are bool=1, char=1, int=4, long long=8, float=4, double=8 bytes, but `sizeof` output is the evidence for the actual compiler. `INT_MAX` is normally 2,147,483,647 and `LLONG_MAX` is much larger. Three million maximum peak fares total 3,000,000 × 3,600 = 10,800,000,000 paise, which exceeds a 32-bit signed `int`; use `long long`.

Money in integer paise avoids binary floating-point rounding. In mixed expressions, integer operands may be promoted or converted to a common type. For example, `7 / 2` is integer division and equals 3; assigning it to `double` afterward gives 3.0, not 3.5. `7.0 / 2` or `static_cast<double>(7) / 2` gives 3.5. A `bool` used as an integer converts to 0 or 1.

The rounding demo intentionally adds 0.1 repeatedly to demonstrate floating-point representation error; the current metro fares (whole rupees and 20% surcharge) happen to be exactly representable, but future fractional fares may not be. Each addition is O(1) time and each accumulator is O(1) space.

On the verified run, 100,000 additions of `0.1` produced `10000.0000000188` instead of exactly `10000.0000000000`: a difference of about `0.0000000188` rupees (about `0.00000188` paise). The integer-paise total was exactly 1,000,000 paise (₹10,000).
