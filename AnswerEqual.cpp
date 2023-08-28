/*!
\file
\brief Файл с проверкой совпадения корней и их количества.
*/


#include "header.h"


/*!
 * \brief Сортировка корней.
 *
 * Функция сравнивает корни и сортирует их по возрастанию.
 * \param[out] x1, x2 - корни квадратного или линейного уравнения.
 */

void Sort(double *x1, double *x2)
    {
    assert(x1 != NULL && x2 != NULL);

    if (*x1 < *x2)
        {
        double tmp = 0;
        tmp = *x2;
        *x2 = *x1;
        *x1 = tmp;
        }
    }


/*!
 * \brief Сравнение решения с тестом.
 *
 * Функция сравнивает полученные корни и их количество с тестом программы.
 * Возвращает True, если они совпали, и False, если нет.
 * \param x1, x2 - корни, полученные в результате решения программы.
 *
 */

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
