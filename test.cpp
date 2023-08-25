#include "header.h"


int TestOne(const Polynome* data)
    {
    Polynome test = {};
    test.a = data->a;
    test.b = data->b;
    test.c = data->c;
    SolveEquation(&test);
    if  (!AnswerEqual(test.x1, test.x2, data->x1, data->x2, test.nRoots, data->nRoots))
        {
        printf("FAILED: X1 = %lf, x2 = %lf, nRoots = %d, exected: xref = %lf, x2ref = %lf "
               "nRootsRef = %d\n", test.x1, test.x2, test.nRoots, data->x1, data->x2, data->nRoots);
        return 0;
        }
    else
        {
        printf("Test OK\n");
        return 1;
        }
    }


void TestAll()
    {
    int nOK = 0;
    FILE *file;
    file = fopen("tests.txt", "r");
    Polynome test = {};
    while (fscanf(file, "%lf %lf %lf %lf %lf %d",
            &test.a, &test.b, &test.c, &test.x1, &test.x2, &test.nRoots) == 6)
        {
        nOK += TestOne(&test);
        }
    printf("Test passed %d\n", nOK);
    }
