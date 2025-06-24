# Choice Machine Implemented on the Call Stack

This repository contains a sample implementation of the **choice machine**,
a concept first introduced in the seminal paper
**"On Computable Numbers, with an Application to the Entscheidungsproblem" by A. M. Turing.**

Turing described the choice machine (or **c-machine**) in Chapter 2, titled *Definitions*,
as a theoretical model of computation that encounters points where multiple transitions are possible.
While he noted that such a machine requires an external operator to resolve these ambiguous configurations,
this implementation takes a different approach: it **systematically and deterministically explores all
possible choices** based on the axiomatic system being executed.

In other words, the choice machine **internalizes choice** and **guarantees decisiveness** while executing an axiomatic system.

It can serve as a **generic algorithmic engine** capable of parsing any kind or form of language grammar.
By internalizing the choice mechanism, the parser becomes **untangled** from ambiguity and can operate as a truly **incremental parser**,
reusing the same algorithmic structure across different contexts.

This model uses the **native call stack** to represent the execution context and branching points,
enabling **exhaustive and context-aware evaluation** of all computational paths.

We may also consider implementing it on a **dedicated stack** instead of relying on the native call stack.
This would enable us to **pause execution**, **save the entire machine state** in one step, and **resume it later**—
allowing for incremental parsing and efficient multitasking.

---

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
