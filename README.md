# Choice Machine Implemented on the Call Stack

This project is a **color-coded, tree-growing interpreter for context-free grammars**, written in C. It transforms the process of parsing and computation into a recursive, self-organizing system where each color — Pink, Yellow, Red, Green, and Blue — represents a distinct “book” or phase of interpretation, such as branching, recursion, continuation, and return. The system logs reveal a living grammar structure where each node (“book”) links to its parent and upper levels, forming a self-referential tree that evolves as rules are expanded and resolved.

Unlike traditional parsers, this interpreter **handles both direct and indirect left recursion naturally** and **computes all grammatical choices using minimal memory**. Its recursive design grows meaning systematically rather than consuming it linearly, allowing multiple parallel derivations to coexist without duplication or backtracking. Each cycle of computation represents a complete, stable “ring” of understanding — a state of the interpreter that is both self-contained and extendable.

Conceptually, the project stands as a **model of grammatical computation and structural efficiency**. It unites parsing, recursion, and evaluation into a single dynamic system that mirrors organic growth: every expansion guarantees progress, every return conserves space, and every choice is explored deterministically. The result is an interpreter that behaves more like a **self-balancing tree of meaning** than a traditional stack machine — precise, recursive, and intrinsically aware of its own structure.

## 🔧 How to Compile and Run

There are additional supporting files in the repository. Use the following commands to compile and run the main components:

### ▶️ Interactive Debugger

```bash
gcc -O3 -Wall s.c draw.c -o s -lraylib -lm && ./s
```

This launches an **interactive debugger** that visualizes the machine’s operation and decision-making flow.

### 🧮 Sample Use Case

```bash
gcc -O3 -Wall calc.c -o calc && ./calc
```

This compiles and runs a calculator implemented as an **axiomatic system**,
defined by a context-free grammar (CFG) with contextual rules.

---

![Screenshot](assets/ss_006.png)
