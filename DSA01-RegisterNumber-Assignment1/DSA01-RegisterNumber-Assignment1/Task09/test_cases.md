# Task 9 — Test Plan and Results

The executable input format is: `initial_balance_paise recharge_paise zone_number hour`. Zone 1=Inner, 2=Middle, 3=Outer. Use recharge `0` for ordinary fare tests.

| Test | Input | Expected result | Purpose |
|---|---|---|---|
| Inner off-peak | `10000 0 1 12` | fare 1000; balance 9000 | normal zone |
| Inner peak | `10000 0 1 8` | fare 1200; balance 8800 | Inner surcharge |
| Middle off-peak | `10000 0 2 12` | fare 2000; balance 8000 | normal zone |
| Middle peak | `10000 0 2 8` | fare 2400; balance 7600 | peak start included |
| Outer off-peak | `10000 0 3 12` | fare 3000; balance 7000 | normal zone |
| Outer peak | `10000 0 3 17` | fare 3600; balance 6400 | peak start included |
| 10 AM off-peak | `10000 0 1 10` | fare 1000; balance 9000 | end of morning peak excluded |
| 8 PM off-peak | `10000 0 3 20` | fare 3000; balance 7000 | end of evening peak excluded |
| Leaves exactly ₹50 | `6000 0 1 12` | fare 1000; balance 5000 | allowed boundary |
| Below minimum after fare | `5999 0 1 12` | denied | does not deduct |
| Unknown zone | `10000 0 4 12` | invalid zone or hour | reject invalid zone |
| Negative recharge | `10000 -100 1 12` | invalid recharge | reject negative recharge |
| Letters for hour | `10000 0 1 x` | invalid input | stream failure is detected |

For a five-journey hand calculation with initial balance ₹200, assume zones/hours: Inner 12 (₹10), Middle 8 (₹24), Outer 20 (₹30), Inner 17 (₹12), Middle 12 (₹20). Total fare = ₹10+₹24+₹30+₹12+₹20 = ₹96; remaining balance = ₹104. This five-journey sum is a hand calculation; the single-journey executable is used to test each rule independently.

A table-driven test loop can store each input and expected result and iterate through t cases: O(t) time and O(t) space for the test table. Adding a boundary case is then a new row rather than a new hand-written conditional.


## Verified actual outputs

```text
Inner off-peak
Input: 10000 0 1 12
Output: Fare paise=1000
Balance paise=9000
Exit code: 0

Inner peak
Input: 10000 0 1 8
Output: Fare paise=1200
Balance paise=8800
Exit code: 0

Middle off-peak
Input: 10000 0 2 12
Output: Fare paise=2000
Balance paise=8000
Exit code: 0

Middle peak
Input: 10000 0 2 8
Output: Fare paise=2400
Balance paise=7600
Exit code: 0

Outer off-peak
Input: 10000 0 3 12
Output: Fare paise=3000
Balance paise=7000
Exit code: 0

Outer peak
Input: 10000 0 3 17
Output: Fare paise=3600
Balance paise=6400
Exit code: 0

10 AM off-peak
Input: 10000 0 1 10
Output: Fare paise=1000
Balance paise=9000
Exit code: 0

8 PM off-peak
Input: 10000 0 3 20
Output: Fare paise=3000
Balance paise=7000
Exit code: 0

exactly Rs 50 remains
Input: 6000 0 1 12
Output: Fare paise=1000
Balance paise=5000
Exit code: 0

below Rs 50 denied
Input: 5999 0 1 12
Output: Denied (low balance)
Exit code: 0

unknown zone
Input: 10000 0 4 12
Output: Invalid zone or hour
Exit code: 0

negative recharge
Input: 10000 -100 1 12
Output: Invalid recharge
Exit code: 0

nonnumeric hour
Input: 10000 0 1 x
Output: Invalid input
Exit code: 0

```
