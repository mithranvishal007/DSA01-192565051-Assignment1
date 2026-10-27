# Task 10 — Expectations versus Execution

For a controlled comparison, the code uses the maximum current fare of 3,600 paise (₹36) for every journey. Because 36.0 and the resulting integer rupee totals are exactly representable at these magnitudes, the double rupee total and integer-paise total agree for these specific inputs:

| Journeys | Exact total paise | Exact total rupees | Fits signed 32-bit `int` in paise? |
|---:|---:|---:|---|
| 20,000 | 72,000,000 | ₹720,000 | Yes |
| 500,000 | 1,800,000,000 | ₹18,000,000 | Yes (below INT_MAX, narrowly) |
| 3,000,000 | 10,800,000,000 | ₹108,000,000 | No |

A signed 32-bit `int` accumulator would overflow for the third case; signed overflow is undefined behaviour, so do not rely on a particular wrapped result. `long long` safely stores the exact paise total. `double` is wide enough for these totals and the chosen whole-rupee fares, but other fractional fare values can accumulate rounding error. A separate repeated-addition experiment in Task 3 demonstrates that risk. Each addition is O(1) time; each accumulator is O(1) space (typically 4 bytes for int, 8 for long long/double on this compiler). Compile with `-Wall -Wextra`; warnings should be reviewed rather than ignored.
