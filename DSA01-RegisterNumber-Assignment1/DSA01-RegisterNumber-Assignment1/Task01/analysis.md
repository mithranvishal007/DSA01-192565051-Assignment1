# Task 1 — Understand the Problem and Identify the Objects

## Assumptions and rules
- Zone base fares are Inner = ₹10, Middle = ₹20, Outer = ₹30.
- Peak hours are [08:00, 10:00) and [17:00, 20:00): start is included, end is excluded. Thus 08:00 and 17:00 are peak; 10:00 and 20:00 are off-peak.
- A peak surcharge is 20% of the base fare. The current base fares produce whole-paise results.
- Money is stored as integer paise. A journey is permitted only when the remaining balance is at least 5,000 paise (₹50).
- Student/senior concessions are mentioned in the scenario but their rates are not specified; they must not be guessed. They are represented as a future policy requirement.

## Objects, data and behaviour
| Object | Data | Behaviour / justification |
|---|---|---|
| SmartCard | card ID, balance in paise | checks eligibility, deducts fare, rejects an invalid deduction; owns the balance invariant |
| Passenger | passenger ID, category (regular/student/senior) | supplies eligibility for a concession; category belongs to the person, not the journey |
| Journey | origin/destination or zone, hour, weekend flag | records what is being charged and when; supports audit and test reproduction |
| Zone | strongly typed zone value | identifies the fare band without magic numbers |
| FareTable / FarePolicy | base fares and surcharge/discount rules | centralizes pricing so one rule change does not require editing many functions |

## Procedural versus object-oriented style
A procedural design would use a balance variable and free functions such as `calculateFare(zone, hour)` and `canTravel(balance, fare)`. An OOP design keeps state and operations together: `SmartCard::canTravel` checks the invariant and `SmartCard::deduct` changes the private balance only after validation. Both designs can run in O(1) time per journey and use O(1) state per card. The OOP design usually limits a fare-rule change to the policy/fare class; procedural code can also be clean, but shared globals and scattered rules increase the number of edit locations and the risk of inconsistent updates.

## OOP principles in this system
- Encapsulation: `SmartCard` keeps `balancePaise` private and validates every deduction.
- Abstraction: callers ask `fareFor(...)` or `canTravel(...)` without needing the arithmetic details.
- Inheritance: `Passenger` could be a base type with `StudentPassenger` and `SeniorPassenger` variants if their policies differ; composition may be simpler if only a category flag is needed.
- Polymorphism: a `ConcessionPolicy` interface could let student and senior policies implement their own discount calculation.

## Correctness rules
1. A base fare is selected from one authoritative fare table.
2. Peak time uses inclusive starts and exclusive ends: `((hour >= 8 && hour < 10) || (hour >= 17 && hour < 20))`.
3. Money arithmetic is in paise; do not use floating-point money for settlement.
4. A journey is accepted only if `balance - fare >= 5000`.
5. Invalid zones, hours outside 0–23 and negative recharges are rejected.
6. A rejected journey must not change the balance.
7. Each accepted fare and balance change is auditable.

## Complexity
For a fixed three-zone table, fare calculation and balance validation are O(1) time. Stored card state is O(1) space per card. If journeys are processed as a batch of J journeys, total processing is O(J) time. Adding a new zone should change one central policy definition, not multiple duplicated fare literals.
