/*!
\file
\brief Заголовочный файл программы.

*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <Windows.h>
#include <wincon.h>
#include <stdlib.h>
#include <assert.h>


/*!
 * \brief Объявления параметров.
 *
 * enum обЪявляет имена, которые являются целочисленными константами.
 * \param no_roots - нет решений.
 * \param one_root - одно решение.
 * \param two_roots - два решения.
 * \param inf_roots - бесконечное количество решений.
 */

enum solutions
    {
    no_roots,
    one_root,
    two_roots,
    inf_roots
    };


/*!
 * Структура используется для всей программы.
 * \param a, b, c - коэффиценты квадратного или линейного уравнения.
 * \param x1, x2 - решения.
 * \param nRoots - количество решений.
 */

struct Polynome
    {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int nRoots;
    };


void ClearBuffer();
int SolveSquare(Polynome*);
bool check(double i, double j);
int SolveLinear(Polynome*);
void PrintAnswer(Polynome*);
void SolveEquation(Polynome*);
void InputCoef(double *a);
void Sort(double *x1, double *x2);
bool AnswerEqual(double x1, double x2, double xref, double x2ref, int nRoots, int nRootsRef);
int TestOne(const Polynome*);
void TestAll(const char* filename);
void CheckingCMDarguments(int argc, char* argv[]);
