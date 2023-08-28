/*!
\file
\brief Основной файл программы. Этот файл запускает программу.
*/

/*! \mainpage Программа решающая квадратное уравение
*
*   Я люблю кошек и программирование.
*
*   мяу
*/

#include "header.h"

/*!
 * \brief Запускает программу, которая решает квадратное или линейное уравнение уравнение.
 */


int main(int argc, char* argv[])
     {
     #ifdef TEST
        CheckingCMDarguments(argc, argv);
     #endif

     Polynome data = {};

     printf("Enter equation coefficients\n");

     InputCoef(&data.a);
     InputCoef(&data.b);
     InputCoef(&data.c);

     SolveEquation(&data);

     PrintAnswer(&data);

     return 0;
     }


/*!
 * \brief Принимает значения коэффицента квадратного или линейного уравнения.
 *
 * Функция считывает коэффицент квадратного или линейного уравнения.
 * В случае, если введены не числа, просит повторить попытку.
 * \param[out] a - параметр квадратного или линейного уравнения.
 */

void InputCoef(double *a)
    {
    while (scanf("%lf", a) != 1)
        {
        ClearBuffer();
        printf("Re-enter value\n");
        }
    }


/*!
 * \brief Вывод решения квадратного или линейного уравнения.
 *
 * Функция принимает структуру data и выводит решение квадратного или линейного уравнения.
 * В зависимости от ответа цвет текста в консоли разный.
 * нет решений - Красный цвет.
 * 1 решение - Желтый цвет.
 * 2 решения - Зеленый цвет.
 * бесконечное количество решений - Фиолетовый цвет.
 * \param[in] data - структура с коэффицентами, корнями и количеством корней квадратного или линейного уравнения.
 */


void PrintAnswer(Polynome* data)
    {
    switch (data->nRoots)
        {
        case no_roots:
                SetColor(RED_COLOR);
                printf ("The equation has no solutions\n");
                SetColor(DEFAULT_COLOR);
                system("pause");
                break;

        case one_root:
                SetColor(YELLOW_COLOR);
                printf ("The equation has a unique solution: %lf\n", data->x1);
                SetColor(DEFAULT_COLOR);
                system("pause");
                break;

        case two_roots:
                SetColor(GREEN_COLOR);
                printf ("The equation has two solutions:\n 1) %lf  2) %lf\n", data->x1, data->x2);
                SetColor(DEFAULT_COLOR);
                system("pause");
                break;


        case inf_roots:
                SetColor(PURPLE_COLOR);
                printf ("The equation has an infinite number of solutions\n");
                SetColor(DEFAULT_COLOR);
                system("pause");
                break;

        default: printf ("main(): ERROR: nRoots = %d\n", data->nRoots);

        }
    }


/*!
 * \brief Сравнение чисел типа double.
 *
 * Функция сравнивает два числа и возвращает логическое значение типа bool.
 * \param[in] i, j - параметры для сравнения.
 */

bool check(double i, double j)
    {
    const double EPS = 1e-9;
    return fabs(i - j) < EPS;
    }

/*!
 * Функция очистки буффера.
 */

void ClearBuffer()
    {
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }


int SetColor(WORD nameofcolor)
    {
    return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nameofcolor);
    }
































