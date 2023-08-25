#include "header.h"



int main()
     {
     Polynome data = {};

     TestAll();

     printf("Enter equation coefficients\n");

     InputCoef(&data.a);
     InputCoef(&data.b);
     InputCoef(&data.c);

     SolveEquation(&data);

     PrintAnswer(&data);

     return 0;
    }


void InputCoef(double *a)
    {
    int ch;
    while (scanf("%lf", a) != 1)
        {
        while ((ch = getchar()) != '\n')
            {
            }
        printf("Re-enter value\n");

        }
    }


void PrintAnswer(Polynome* data)
    {
    switch (data->nRoots)
        {
        case no_roots: printf ("The equation has no solutions\n");
                break;

        case one_root: printf ("The equation has a unique solution: %lf\n", data->x1);
                break;

        case two_roots: printf ("The equation has two solutions:\n 1) %lf  2) %lf\n", data->x1, data->x2);
                break;

        case INF: printf ("The equation has an infinite number of solutions\n");
                break;

        default: printf ("main(): ERROR: nRoots = %d\n", data->nRoots);

        }
    }


bool check(double i, double j)
    {
    const double EPS = 1e-9;
    return fabs(i - j) < EPS;
    }






























