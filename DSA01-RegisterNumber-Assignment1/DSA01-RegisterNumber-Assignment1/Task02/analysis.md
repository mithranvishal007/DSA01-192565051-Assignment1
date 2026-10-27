# Task 2 — Tokens, Keywords, Identifiers and Constants

- Keywords: `int`, `return`, `enum`, `class`, `if`.
- Identifiers: `BASE_PAISE`, `PEAK_SURCHARGE_PERCENT`, `MIN_BALANCE_PAISE`, `Zone`.
- Constants/literals: `1000`, `2000`, `3000`, `20`, `5000`.
- Operators: `=`, `==`, `<<`, `?:`, `+`.
- Punctuators: `{}`, `()`, `;`, `,`, `[]`.

`#define` is a preprocessor text substitution: it has no type or normal scope and can cause surprising substitutions. `const` prevents modification after initialization. `constexpr` requires a compile-time constant when possible and is suitable for fixed fare values. `enum class Zone` is scoped and does not implicitly convert to `int`, reducing accidental mixing of zone values and unrelated integers.

Identifier conventions: descriptive names, `PascalCase` for types (`SmartCard`, `FarePolicy`), `camelCase` for functions (`calculateFare`) and uppercase snake case for constants (`MIN_BALANCE_PAISE`). Avoid spaces, leading digits and C++ keywords.

Alternative using macros: `#define INNER_FARE 1000` etc. It can compile to the same machine operations and does not inherently change runtime complexity, but macros lack type checking and scope. `constexpr` and `enum class` are safer and normally require no extra runtime storage for compile-time constants. Looking up a fixed-size fare is O(1) time either way.
