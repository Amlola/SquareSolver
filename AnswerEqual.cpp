#include "header.h"


void Sort(double *x1, double *x2)
    {
    if (check(*x1, *x2))
        {
        double tmp = 0;
        tmp = *x2;
        *x2 = *x1;
        *x1 = tmp;
        }
    }


bool AnswerEqual(double x1, double x2, double xref, double x2ref, int nRoots, int nRootsRef)
    {
    Sort(&x1, &x2);
    Sort(&xref, &x2ref);
    if (!check(x1, xref) || !check(x2, x2ref) || nRoots != nRootsRef)
        {
        return 0;
        }
    else
        {
        return 1;
        }
    }
