# Task 8 — Safe Input and Formatted Output

The program checks each extraction using `if (cin >> value)`. On failure it prints an error, calls `cin.clear()` to reset the stream's fail state, and `cin.ignore(max, '\n')` to discard the invalid line before retrying. It validates zone and hour ranges before calculating a fare. Fare is stored in paise; output formats the whole-rupee and two-digit paise parts with `setw(2)` and `setfill('0')`.

Alternative: `getline` reads a full line, then `stoi` inside `try/catch` converts it. Parsing a line of length L is O(L) time and O(L) buffer space. Stream extraction is also linear in consumed input and generally uses a small stream buffer; `getline`/`stoi` makes whole-line validation easier, while `cin >>` is convenient for token-based input. Invalid input must always be consumed to avoid repeatedly failing on the same characters.

`getline_parse.cpp` demonstrates the alternative whole-line parser. `stoi` throws on malformed input; the code also checks that the entire line was consumed and validates the 0–23 range.
