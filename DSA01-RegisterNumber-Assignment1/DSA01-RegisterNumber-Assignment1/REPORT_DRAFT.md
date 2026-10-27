# Assignment 1 Report Draft

**Assignment title:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System  
**Student:** [Enter your full name]  
**Register number:** [Enter your register number]  
**GitHub repository:** [Paste your working repository URL after publishing]

## Environment and method
Prepared for C++17. Compiler version in the preparation environment: g++ (Debian 14.2.0-19). Build command: `g++ -std=c++17 -Wall -Wextra -pedantic file.cpp -o program`. Each program should be recompiled and executed by the student before submission. The `outputs/` files record the outputs generated during this preparation run; replace generated output previews with genuine screenshots if required by faculty.

## Task-by-task report
Use each task folder's `analysis.md`, `pseudocode.md`, or `test_cases.md` as the detailed evidence for that task. This report draft provides the main conclusions:

1. **Object analysis:** SmartCard owns balance and validation; Journey records a trip; Zone represents fare bands; FarePolicy centralizes pricing. Balance must never fall below ₹50 after an accepted trip.
2. **Tokens/constants:** Use named `constexpr` fare/surcharge/minimum-balance constants and `enum class Zone`; these are safer than untyped macros.
3. **Data types:** Store money in `long long` paise. A 3,000,000-journey maximum-fare total is 10,800,000,000 paise, beyond signed 32-bit `int`.
4. **Conversions:** Integer division occurs before assignment to `double`; explicit casting changes division to floating-point. Character promotion, integer-to-bool and signed-to-unsigned conversions are explained in Task04.
5. **Precedence:** Multiplication precedes addition; parentheses override precedence; postfix and prefix increments differ. Negative integer division truncates toward zero.
6. **Control flow:** `switch` chooses the zone base fare; `if` applies surcharge and validates balance; the peak interval uses inclusive starts and exclusive ends.
7. **Design styles:** Procedural functions and a SmartCard class have the same asymptotic complexity, but private balance plus validated methods protects invariants.
8. **Safe I/O:** Check stream extraction, clear fail state, discard invalid input, validate ranges and format money from integer paise.
9. **Testing:** Test all zones, peak/off-peak boundaries, exact ₹50 remaining balance, invalid zone, negative balance/recharge and nonnumeric hour input.
10. **Scale comparison:** 20,000 × 3,600 = 72,000,000 paise; 500,000 × 3,600 = 1,800,000,000 paise; 3,000,000 × 3,600 = 10,800,000,000 paise. The last value does not fit a 32-bit signed int.
11. **Recommendation:** Use integer paise, centralized fare policy, `enum class`, and a private SmartCard balance. Consider validated configuration files only if fares change frequently.
12. **Design challenge:** Add Airport at ₹60, a non-combinable weekend 10% discount and a MonthlyPass covering two zones. The code assumes weekend discount takes precedence over peak surcharge.

## Verification checklist to complete before submission
- [ ] Replace student and register-number placeholders.
- [ ] Compile and execute every `.cpp` file on your own system.
- [ ] Review and understand the output-prediction explanations.
- [ ] Capture actual IDE/terminal screenshots and place them in the corresponding task folder.
- [ ] Add a UML diagram for SmartCard, FarePolicy and MonthlyPass if required by the report rubric.
- [ ] Create the GitHub repository with the exact required name.
- [ ] Commit each task progressively (at least one commit per task).
- [ ] Confirm the public link or add faculty as a collaborator for a private repository.
- [ ] Submit the working repository URL and final report through Google Classroom.
