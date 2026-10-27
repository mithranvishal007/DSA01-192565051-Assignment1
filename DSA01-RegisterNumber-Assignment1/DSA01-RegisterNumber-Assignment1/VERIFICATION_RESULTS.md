# Full compilation verification

Command: `g++ -std=c++17 -Wall -Wextra -pedantic source.cpp -o program`

All 16 C++ source files compiled successfully. Task04/predict.cpp intentionally emits a `-Wsign-compare` warning because it demonstrates the signed/unsigned conversion asked about in the assignment.

## Task02/constants.cpp
- Compile exit code: 0
- Warnings: none
## Task03/rounding_demo.cpp
- Compile exit code: 0
- Warnings: none
## Task03/types.cpp
- Compile exit code: 0
- Warnings: none
## Task04/explicit_conversions.cpp
- Compile exit code: 0
- Warnings: none
## Task04/predict.cpp
- Compile exit code: 0
- Warnings:
```text
/mnt/data/DSA01-RegisterNumber-Assignment1/Task04/predict.cpp: In function ‘int main()’:
/mnt/data/DSA01-RegisterNumber-Assignment1/Task04/predict.cpp:14:21: warning: comparison of integer expressions of different signedness: ‘int’ and ‘unsigned int’ [-Wsign-compare]
   14 |     std::cout << (s < u ? "s < u" : "s >= u") << '\n';
      |                   ~~^~~
```
## Task05/peak_table.cpp
- Compile exit code: 0
- Warnings: none
## Task05/predict.cpp
- Compile exit code: 0
- Warnings: none
## Task06/fare_array.cpp
- Compile exit code: 0
- Warnings: none
## Task06/fare_todo.cpp
- Compile exit code: 0
- Warnings: none
## Task07/oop.cpp
- Compile exit code: 0
- Warnings: none
## Task07/procedural.cpp
- Compile exit code: 0
- Warnings: none
## Task08/getline_parse.cpp
- Compile exit code: 0
- Warnings: none
## Task08/safe_io.cpp
- Compile exit code: 0
- Warnings: none
## Task09/fare_system.cpp
- Compile exit code: 0
- Warnings: none
## Task10/totals.cpp
- Compile exit code: 0
- Warnings: none
## Task12/revised_design.cpp
- Compile exit code: 0
- Warnings: none
