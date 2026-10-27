# DSA01-RegisterNumber-Assignment1

**Student name:** [Enter your full name]  
**Register number:** [Enter your register number]  
**Course:** C++ Programming / OOP  
**Assignment:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System

> Before submission, replace the two placeholders above, review every explanation, run the commands on your own system, capture genuine IDE/terminal screenshots, and commit the tasks progressively. This folder is a prepared working solution, not proof of your personal GitHub history or Google Classroom submission.

## Compiler and build command
- Compiler used for verification in the preparation environment: `g++ (Debian 14.2.0-19)`
- Standard: C++17
- Compile command: `g++ -std=c++17 -Wall -Wextra -pedantic source.cpp -o program`
- Run command: `./program` (Windows MinGW: `program.exe`)

## Task map
| Folder | Contents |
|---|---|
| Task01 | OOP object analysis, invariants, procedural comparison and complexity |
| Task02 | Token/constant demo and macro-versus-constexpr discussion |
| Task03 | Data type/sizeof demo and floating-point rounding experiment |
| Task04 | Conversion output-prediction program and explanation |
| Task05 | Operator-precedence output-prediction program and explanation |
| Task06 | Completed TODO fare program, pseudocode and boundary checks |
| Task07 | Procedural and OOP SmartCard implementations |
| Task08 | Safe input recovery and formatted fare output |
| Task09 | Fare calculation implementation and test matrix |
| Task10 | Network-scale total comparison and integer overflow analysis |
| Task11 | Final design recommendation |
| Task12 | Revised four-zone/weekend/pass design and impact analysis |

## Running programs
Each `.cpp` file can be compiled independently. Example:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic Task06/fare_todo.cpp -o task06
./task06
```
The `outputs/` subfolders contain captured standard output from verification runs, and `input.txt` files contain sample input where relevant. Output preview images are generated from captured output; replace them with screenshots from your own terminal/IDE if your instructor specifically requires actual screenshots.

## Complexity summary
- Fixed-size fare lookup / balance check: O(1) time and O(1) extra space per journey.
- Processing J journeys: O(J) time.
- Prime/factor-style loops are not part of this fare assignment; output-prediction snippets execute in O(1) except the short loop in Task 5, which is O(1) here because its upper bound is fixed at 10.
- Table-driven test suite of t cases: O(t) time and O(t) space for stored test cases.

## GitHub progressive commits
After creating the repository, add one task at a time. Example:
```bash
git init
git add README.md Task01
git commit -m "Complete Task 1: OOP problem analysis"
# repeat git add + git commit for Task02 ... Task12
git branch -M main
git remote add origin https://github.com/<your-username>/DSA01-<RegisterNumber>-Assignment1.git
git push -u origin main
```
Do not claim a commit was made until the command succeeds. Add the course faculty as a collaborator if the repository is private. Submit the actual repository URL and report through Google Classroom yourself.
