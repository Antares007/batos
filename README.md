# Choice Machine Implemented on the Call Stack

This repository contains a sample implementation of the choice machine, a concept first introduced by Alan Turing in his seminal paper On Computable Numbers, with an Application to the Entscheidungsproblem.

Turing described the choice machine (or c-machine) in Chapter 2, titled Definitions, as a theoretical model of computation that encounters points where multiple transitions are possible. While he noted that such a machine requires an external operator to resolve these ambiguous configurations, this implementation takes a different approach: it systematically and deterministically explores all possible choices based on the axiomatic system being executed.

This model uses the native call stack to represent the execution context and branching choices, enabling exhaustive and context-aware evaluation of all computational paths.

---

## 🔧 How to Compile and Run

There are additional supporting files in the repository. Use the following commands to compile and run the main components:

### ▶️ Interactive Debugger
```bash
gcc -O3 -Wall s.c draw.c -o s -lraylib -lm && ./s
````

This launches an interactive debugger that visualizes the machine's movement.

### 🧮 Sample Use Case

```bash
gcc -O3 -Wall calc.c -o calc -lraylib -lm && ./calc
```

This compiles and runs a sample use case built on top of the machine.

---

![Screenshot](assets/ss_006.png)

