# fast\_arithmetics\_142111

A hobby project aim to learn about fast way to implement efficient arithmetics (multiplication, addition, ...) on finite field **GF(2^142-111)**. Code is written in C and some of them are in-line assembly embedded in C. This is a branch created from the original project aiming to understand the fast arithmetics behind Curve25519.

The instruction set written for this library is from Intel x64, which uses registers *r8, r9, ..., r15* as immediate holders for some of the computations.

## Run code
- You can run `make main` to compile the main program from source.
- Or, `make run` to compile and run right away.
- `make gdb` to debug the program with `gdb` *(if there isn't `gdb` on your machine, install it first :))*.
