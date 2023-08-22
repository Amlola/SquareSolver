#include "TXLib.h"
#include <stdio.h>
#include <math.h>


const double EPS = 1e-9;
int SolveSquare (double a, double b, double c, double *sol1, double *sol2);
bool check(double i, double j);
int SolveLine(double b, double c, double *sol1);


int main()
     {
     double a = 0, b = 0, c = 0;
     // Input Answer()
     printf("Введите первый коэффицент уравнения\n");
     // Возврачаемое значение функции scanf() и прочитать про буфферизованный ввод
     scanf("%lf", &a);
     printf("Введите второй коэффицент уравнения\n");
     scanf("%lf", &b);
     printf("Введите третий коэффицент уравнения\n");
     scanf("%lf", &c);

     double sol1 = 0, sol2 = 0;
                  // SolveEquation()
     int nRoots = SolveSquare(a, b, c, &sol1, &sol2);

    // PrintAnswer()
    switch (nRoots)
        {
        case 0: printf ("Решений нет\n");
                break;

        case 1: printf ("Уравнение имеет единственный корень: %lf\n", sol1);
                break;

        case 2: printf ("Уравнение имеет два корня: %lf, %lf\n", sol1, sol2);
                break;

        case 3: printf ("Уравнение имеет бесконечное количество решений\n");
                break;

        default: printf ("main(): ERROR: nRoots = %d\n", nRoots);
                return 1;

        }
    return 0;
    }



    bool check(double i, double j)
        {
        // EPS??
        return fabs(i - j) < EPS;
        }


    int SolveSquare(double a, double b, double c, double *sol1, double *sol2)
        {
        if (check(a, 0))
            {
            return SolveLine(b, c, sol1);
            }
        else
            {
            double d = b*b - 4*a*c;
            if (check(d, 0))
                {
                *sol1 = *sol2 = -b / (2*a);
                return 1;
                }
            else if (d < 0)
                {
                return 0;
                }
            else
                {
                double sqrt_d = sqrt(d);
                *sol1 = (-b - sqrt_d) / (2 * a);
                *sol2 = (-b + sqrt_d) / (2 * a);
                return 2;
                }
            }
        }


        int SolveLine(double b, double c, double *sol1)
            {
            if (check(b, 0))
                {
                if (check(c, 0))
                    {
                    return 3;
                    }
                else
                    {
                    return 0;
                    }
                }
            else
                {
                *sol1 = -c / b;
                return 1;
                }
            }
