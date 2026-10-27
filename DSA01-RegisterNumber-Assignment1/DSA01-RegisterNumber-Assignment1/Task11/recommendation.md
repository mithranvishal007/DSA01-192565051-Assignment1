# Task 11 — Final Design Recommendation

Recommend a hybrid object-oriented design: `enum class Zone`, one centralized compile-time fare table, integer paise stored in `long long`, an explicit `isPeakHour` function, a `FarePolicy`/`fareFor` function, and a `SmartCard` class with a private balance and validated `canTravel`/`deduct` methods. This gives exact settlement arithmetic and keeps the ₹50 minimum-balance invariant in one place.

A fare revision changes one fare table entry or policy constant, followed by regression tests. The current design is O(1) time per journey and O(1) per-card state; processing J journeys is O(J). Limitations: the initial three-zone design does not include concession rates because the assignment does not specify them; it also assumes hourly granularity rather than minute-level timestamps, and compile-time fares require rebuilding/redeploying after a fare revision.

For a larger network or frequent policy updates, reading a validated configuration file at startup is a reasonable next step. Reading z fare values takes O(z) startup time and O(z) memory, and avoids recompiling for each fare update. The program must reject missing, negative or malformed values and should version/audit the configuration. For only three fixed fares, constexpr values are simpler and safer.

Evidence basis: Task 6's sample execution demonstrates exact ₹10.00 and ₹36.00 fares and refusal when a fare would leave less than ₹50. Task 9's test matrix checks time boundaries and the exact minimum-balance boundary. Task 10's calculation shows why `long long` is needed for network-scale paise totals.
