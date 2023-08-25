#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <ctype.h>


enum solutions
    {
    no_roots,
    one_root,
    two_roots,
    INF
    };


struct Polynome {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int nRoots;
};


int SolveSquare(Polynome*);
bool check(double i, double j);
int SolveLinear(Polynome*);
void PrintAnswer(Polynome*);
void SolveEquation(Polynome*);
void InputCoef(double *a);
void Sort(double *x1, double *x2);
bool AnswerEqual(double x1, double x2, double xref, double x2ref, int nRoots, int nRootsRef);
int TestOne(const Polynome*);
void TestAll();
