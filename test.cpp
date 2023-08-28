/*!
\file
\brief Файл, тестирующий программу.

этот файл содержит функции, которые запускают проверку программы тестами.
*/


#include "header.h"


/*!
 * \brief Запуск одного теста.
 *
 * Функция печатает ошибку в случае не совпадение корней или их количества.
 * В ином случае сообщает, что все тест прошел успешно.
 * \param[out] data - структура с коэффицентами, корнями и количеством корней квадратного или линейного уравнения.
 */

int TestOne(const Polynome* data)
    {
    assert(data != NULL);
    assert(isfinite(data->a));
    assert(isfinite(data->b));
    assert(isfinite(data->c));

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


/*!
 * \brief Запуск всех тестов.
 *
 * Функция принимает название файла.
 * Если такого файла не найдено, то печатает, что он не найден.
 * В ином случае возвращает количество пройденных тестов в файле.
 */

void TestAll(const char* filename)
    {

    int nOK = 0;
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
        {
        printf("FILE: %s can't open\n", filename);
        }

    Polynome test = {};
    while (fscanf(file, "%lf %lf %lf %lf %lf %d",
            &test.a, &test.b, &test.c, &test.x1, &test.x2, &test.nRoots) == 6)
        {
        nOK += TestOne(&test);
        }
    printf("Test passed %d\n", nOK);
    }


/*!
 * \brief Позволяет пользователю выбрать что запускать.
 *
 * Функция позволяет выбрать пользователю, запускать пользовательский тест или программный.
 * При указании --test в консоли запускает программные тесты.
 * После --test можно указать название своего файла с тестом. Тогда программа запустит его.
 */

void CheckingCMDarguments(int argc, char* argv[])
    {
    if (argc >= 2 && strcmp(argv[1], "--test") == 0)
        {
        if (argc == 2)
            {
            TestAll("tests.txt");
            }
        else
            {
            TestAll(argv[2]);
            }
        }
    }
