/*!
\file
\brief Файл с решением уравнения.

этот файл содержит функции по решению уравнения.
*/


#include "header.h"


/*!
 * \brief Определение вида уравнения.
 *
 * Функция сравнивает старший коэффицент уравнения с 0.
 * Если a = 0, то вызывает функцию SolveLinear.
 * Иначе вызывает функцию SolveSquare.
 * Передает переменной nRoots количество корней уравнения.
 * \param[out] data - структура с коэффицентами, корнями и количеством корней квадратного.
 */

void SolveEquation(Polynome* data)
    {
    assert(data != NULL);
    assert(isfinite(data->a));

    if (check(data->a, 0))
        {
        data->nRoots = SolveLinear(data);
        }
    else
        {
        data->nRoots = SolveSquare(data);
        }
    }


/*!
 * \brief Решение квадратного уравнения.
 *
 * Функция решает квадратное уравнение ax^2 + bx + c = 0.
 * Возвращает константу в зависимости от количества решений.
 * \param[out] data - структура с коэффицентами, корнями и количеством корней квадратного уравнения.
 */

int SolveSquare(Polynome* data)
    {
    assert(data != NULL);
    assert(isfinite(data->a));
    assert(isfinite(data->b));
    assert(isfinite(data->c));

    double d = data->b * data->b - 4 * data->a * data->c;

    if (check(d, 0))
        {
        data->x1 = data->x2 = -(data->b) / (2 * data->a);
        return one_root;
        }
    else if (d < 0)
        {
        return no_roots;
        }
    else
        {
        double sqrt_d = sqrt(d);
        data->x1 = (-(data->b) - sqrt_d) / (2 * data->a);
        data->x2 = (-(data->b) + sqrt_d) / (2 * data->a);
        return two_roots;
        }
    }


/*!
 * \brief Решение линейного уравнения.
 *
 * Функция решает линейное уравнение bx + c = 0.
 * Возвращает константу в зависимости от количества решений.
 * \param[out] data - структура с коэффицентами, корнями и количеством корней линейного уравнения.
 */

int SolveLinear(Polynome* data)
    {
    assert(data != NULL);
    assert(isfinite(data->b));
    assert(isfinite(data->c));

    if (check(data->b, 0))
        {
        if (check(data->c, 0))
            {
            return inf_roots;
            }
        else
            {
            return no_roots;
            }
        }
    else
        {
        data->x1 = -(data->c) / -(data->b);
        return one_root;
        }
    }
