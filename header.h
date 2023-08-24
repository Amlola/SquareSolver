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


struct Tests1 {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int nRoots;
};


int SolveSquare (double a, double b, double c, double *sol1, double *sol2);
bool check(double i, double j);
int SolveLinear(double b, double c, double *sol1);
void PrintAnswer(int nRoots, double sol1, double sol2);
void SolveEquation(double a, double b, double c, double *sol1, double *sol2, int *nRoots);
void InputCoef(double *a);
void Sort(double *x1, double *x2);
bool AnswerEqual(double x1, double x2, double xref, double x2ref, int nRoots, int nRootsRef);
int TestOne(const Tests1*);
void TestAll();
