# High Performance and Parallel Computing Scratchbook

> **repo name:** perf-parallel-computing

A scratch book repository for CAB401_25se2 High Performance and Parallel Computing, a course apart of QUT BDataSc's Advanced Computing for Data Science Minor

## Repository Summaries

### Activity 1.12

> `Activity 1.12` - Contains self paced practical exercise tasks 1 - 7 from *Week 1: The Free Lunch is Over*

##### o3 summary:

`Activity 1.12` walks through increasingly sophisticated experiments with 2-D arrays and matrix multiplication on the CPU. Most sections are wrapped in comments so you enable one “task” at a time.

| Task                                                         | Purpose                                                      | Key details                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **2 – Hello World**                                          | Verify tool-chain (C mode).                                  | Simple `printf("Hello World!\n");`.                          |
| **3 – Matrix Multiply, “Hello World of Parallel Computing”** | Baseline serial matrix-matrix product.                       | • Fixed size `N = 100`.• Random-seeded inputs `A`, `B` (`rand()` with seed 42).• Triple-nested `for` loops compute `C = A × B`.• Prints “done!” when finished. |
| **4 – Saving & Comparing Results**                           | Regression test for correctness across future optimisations. | • Reads a reference result matrix `D` from **log.bin** (binary).• Recomputes `C` exactly as in Task 3 and asserts `C == D` element-wise. |
| **5 – Timing Your Code**                                     | Measure runtime variability.                                 | • Still `N = 100`.• Runs 10 trials; each trial wraps the multiply in `<chrono>` timers and prints seconds elapsed. |
| **6 – Improving Performance**                                | Stress test and highlight cache effects.                     | • Enlarges problem size to `N = 1500` (≈ 3.4 GB of int data, so likely swapped or stack-static).• Moves `A`, `B`, `C` to file-scope (global) to avoid large stack frames.• Uses an intermediate `double total` accumulator for each output element. |
| **7 – Exploring 2-D Array Structures** (active)              | Visualise memory layout and keep timing harness.             | • Small `N = 4` so addresses fit on screen.• Prints the address of every `A[i][j]`, illustrating C’s row-major ordering.• Then repeats the 10-trial timed multiply (still using globals, but small size). |