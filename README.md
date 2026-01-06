# push_swap
The **push_swap** project is a command‑line program that computes an efficient sequence of operations to sort a list of integers. The sorting process is performed using two stacks and a strictly limited set of allowed operations, making the task an algorithmic and structural challenge centered around constrained problem‑solving.

## Purpose
The project explores how complex sorting behavior can be achieved within a minimal operational model. By requiring the program to output an optimized sequence of stack operations rather than performing the sort directly, the project emphasizes control‑flow design, data‑structure organization, and thoughtful algorithm selection.
Core Functionality

The program: 
- Accepts a series of integer arguments.
- Validates and parses input, ensuring correctness and safety.
- Constructs two stacks used throughout the sorting procedure.
- Determines an operation sequence that sorts the values placed in Stack A.
- Outputs the operations in the exact order needed to complete the transformation.

The allowed operations include: 
- **Swap**: interchange the top elements of a stack.
- **Push**: move the top element from one stack to another.
- **Rotate**: shift all elements of a stack upward.
- **Reverse Rotate**: shift all elements downward.

These constraints require a carefully structured approach to produce a minimal or near‑minimal instruction set.

## Sorting Approach

The sorting method adapts based on dataset size:
- Smaller datasets rely on direct, deterministic instruction patterns.
- Larger input sizes benefit from strategies such as chunk segmentation, cost‑based movement, and optimized rotations.

The combination ensures predictable behavior and consistent performance across varying input complexities.

## Output Format
The program prints stack operations line‑by‑line. When executed sequentially, these operations transform the initial unsorted stack into a fully ordered one.

Example:
```
pb
ra
pa
```
## Project Characteristics
The project emphasizes:
- Deterministic control over data transformations
- Efficient logical structuring of stack operations
- Clear separation of concerns within the codebase
- Consistent behavior across all edge cases, including duplicates, invalid input, and extreme values

## Build and usage
```bash
# Clone the repository
git clone git@github.com:miluns/push_swap.git
cd push_swap

# Compile the program
make

# Run the program with multiple numbers as input (example)
./push_swap 1337 2137 42 1301 2001
