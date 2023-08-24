#include "header.h"


int TestOne(const Tests1* data)
    {
    double x1 = 0,x2 = 0;
    int nRoots = 0;
    SolveEquation(data->a, data->b, data->c, &x1, &x2, &nRoots);
    if  (!AnswerEqual(x1, x2, data->x1, data->x2, nRoots, data->nRoots))
        {
        printf("FAILED: X1 = %lf, x2 = %lf, nRoots = %d, exected: xref = %lf, x2ref = %lf "
               "nRootsRef = %d\n", x1, x2, nRoots, data->x1, data->x2, data->nRoots);
        return 0;
        }
    else
        {
        printf("Test OK\n");
        return 1;
        }
    }
