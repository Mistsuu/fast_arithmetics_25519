# fast\_arithmetics\_25519

A hobby project aim to learn about fast way to implement efficient arithmetics (multiplication, power, inverse, square\_root, ...) on finite field **GF(2^255-19)**. Code is written in C and some of them are in-line assembly embedded in C. 

The instruction set written for this library is from Intel x64, which uses registers *r8, r9, ..., r15* as immediate holders for some of the computations.
