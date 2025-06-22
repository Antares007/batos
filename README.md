# Choice Machine Implemented on the Call Stack

This repository contains a sample implementation of the **choice machine**, a concept first introduced by **Alan Turing** in his seminal paper *On Computable Numbers, with an Application to the Entscheidungsproblem*.

Turing described the choice machine (or *c-machine*) in **Chapter 2, titled “Definitions”**, as a theoretical model of computation capable of making non-deterministic choices. Unlike automatic machines, the c-machine requires an external operator when it reaches an ambiguous configuration—something left unresolved in classical computation theory. This implementation models such a machine using the native call stack to represent its execution context and branching choices.

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

