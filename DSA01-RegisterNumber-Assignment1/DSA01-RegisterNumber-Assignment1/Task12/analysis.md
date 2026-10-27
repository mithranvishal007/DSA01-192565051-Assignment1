# Task 12 — Design Challenge: Fourth Zone, Weekend Discount and Monthly Pass

## A. Impact analysis
- Add `Airport` to `enum class Zone` and add ₹60 = 6,000 paise to the fare table.
- Update every switch/table that maps a zone to a fare; a table reduces the number of separate case edits.
- Add a weekend input/flag and a separate discount rule.
- Add `MonthlyPass` to record two covered zones and answer whether a journey is covered.
- Keep `SmartCard` balance private and keep the minimum-balance check centralized.

## B. Evaluate the original design
The original three-case switch can be extended with an Airport case, but every switch must be updated and an omitted case can silently fall through if no default is present. A four-entry table makes the fare data easier to review and is O(1) lookup. The original SmartCard balance/deduction invariant still works, but the fare policy needs a weekend flag and a pass decision before charging.

## C. Revised design and explicit assumption
The program uses a four-entry `array` and a `MonthlyPass` class that covers two chosen zones. Assumption: when a journey is covered by the monthly pass, its fare is zero; the balance remains unchanged. For a weekend journey, the 10% discount takes precedence and the 20% peak surcharge is not applied. Therefore Airport weekday peak = 6,000 + 20% = 7,200 paise (₹72.00), while Airport weekend = 6,000 × 90% = 5,400 paise (₹54.00), even if the hour is peak. This precedence is explicit to avoid combining discounts.

## D. Evidence-based defence
The revised implementation centralizes fares in one table, makes the new zone a single enum value, and separates pass coverage from fare calculation. Table lookup and pass coverage are O(1); per-card state remains O(1). The trade-off is that table ordering must match enum values, so the mapping needs tests. A configuration file would be more flexible for frequent fare changes but adds parsing, validation and startup complexity.
