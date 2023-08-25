#include "header.h"


void SolveEquation(Polynome* data)
    {
    if (check(data->a, 0))
        {
        data->nRoots = SolveLinear(data);
        }
    else
        {
        data->nRoots = SolveSquare(data);
        }
    }


int SolveSquare(Polynome* data)
    {
//    assert(isfinite(a));
//    assert(isfinite(b));
//    assert(isfinite(c));
//    assert(sol1 != null);
//    assert(sol2 != null);

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


int SolveLinear(Polynome* data)
    {
    if (check(data->b, 0))
        {
        if (check(data->c, 0))
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
        data->x1 = -(data->c) / -(data->b);
        return one_root;
        }
    }
