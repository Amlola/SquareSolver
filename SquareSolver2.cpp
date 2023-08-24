#include "header.h"

// Везде переделать на структуры
// Прочитать про аргументы командной строки, чтобы запускать пользовательские тесты
// Разбить на файла
// Прочитать про .bat файлы

int main()
     {
     double a = 0, b = 0, c = 0;
     double sol1 = 0, sol2 = 0;
     int nRoots = 0;
     TestAll();
     printf("Р’РІРµРґРёС‚Рµ РєРѕСЌС„С„РёС†РµРЅС‚С‹\n");

     InputCoef(&a);
     InputCoef(&b);
     InputCoef(&c);

    // SolveEquation()
     SolveEquation(a, b, c, &sol1, &sol2, &nRoots);

    // PrintAnswer()
     PrintAnswer(nRoots, sol1, sol2);
     return 0;
    }



bool check(double i, double j)
    {
    const double EPS = 1e-9; // EPS??
    return fabs(i - j) < EPS;
    }


int SolveSquare(double a, double b, double c, double *sol1, double *sol2)
    {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(sol1 != NULL);
    assert(sol2 != NULL);

    double d = b * b - 4 * a * c;

    if (check(d, 0))
        {
        *sol1 = *sol2 = -b / (2 * a);
        return one_root;
        }
    else if (d < 0)
        {
        return no_roots;
        }
    else
        {
        double sqrt_d = sqrt(d);
        *sol1 = (-b - sqrt_d) / (2 * a);
        *sol2 = (-b + sqrt_d) / (2 * a);
        return two_roots;
        }
    }


int SolveLinear(double b, double c, double *sol1)
    {
    if (check(b, 0))
        {
        if (check(c, 0))
            {
            return INF;
            }
        else
            {
            return no_roots;
            }
        }
    else
        {
        *sol1 = -c / b;
        return one_root;
        }
    }


void PrintAnswer(int nRoots, double sol1, double sol2)
    {
    switch (nRoots)
        {
        case no_roots: printf ("Р РµС€РµРЅРёР№ РЅРµС‚\n");
                break;

        case one_root: printf ("РЈСЂР°РІРЅРµРЅРёРµ РёРјРµРµС‚ РµРґРёРЅСЃС‚РІРµРЅРЅС‹Р№ РєРѕСЂРµРЅСЊ: %lf\n", sol1);
                break;

        case two_roots: printf ("РЈСЂР°РІРЅРµРЅРёРµ РёРјРµРµС‚ РґРІР° РєРѕСЂРЅСЏ: %lf, %lf\n", sol1, sol2);
                break;

        case INF: printf ("РЈСЂР°РІРЅРµРЅРёРµ РёРјРµРµС‚ Р±РµСЃРєРѕРЅРµС‡РЅРѕРµ РєРѕР»РёС‡РµСЃС‚РІРѕ СЂРµС€РµРЅРёР№\n");
                break;

        default: printf ("main(): ERROR: nRoots = %d\n", nRoots);

        }
    }


void SolveEquation(double a, double b, double c, double *sol1, double *sol2, int *nRoots)
    {


    if (check(a, 0))
        {
        *nRoots = SolveLinear(b, c, sol1);
        }
    else
        {
        *nRoots = SolveSquare(a, b, c, sol1, sol2);
        }
    }





void InputCoef(double *a)
    {
    int ch;
    while (scanf("%lf", a) != 1)
        {
        while ((ch = getchar()) != '\n')
            {
            }
        printf("Р’РІРµРґРёС‚Рµ Р·РЅР°С‡РµРЅРёСЏ Р·Р°РЅРѕРІРѕ\n");

        }
    }



void TestAll()
    {
    int nOK = 0;
    FILE *file;
    file = fopen("tests.txt", "r");
    Tests1 test = {};
    while (fscanf(file, "%lf %lf %lf %lf %lf %d",
            &test.a, &test.b, &test.c, &test.x1, &test.x2, &test.nRoots) == 6)
        {
        nOK += TestOne(&test);
        }
    printf("Test passed %d\n", nOK);
    }


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
    // check()
    if (!check(x1, xref) || !check(x2, x2ref) || nRoots != nRootsRef)
        {
        return 0;
        }
    else
        {
        return 1;
        }
    }




























