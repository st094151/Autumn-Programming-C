#pragma once
#if !(defined myLIB1_H) || !(defined myLIB2_H)

#ifdef myLIB2_H
#define myLIB1_H
#endif

int Collatz(int, int);
void circle(int);

#define myLIB2_H
#endif