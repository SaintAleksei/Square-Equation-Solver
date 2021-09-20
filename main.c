#include "solve_square.h"

//-----------------------------------------------------------------------------

int main ()
{
    printf ("# Square equation solver (c) SaintAleksei\n"
            "#\n"
            "# Enter coefficients from ax^2 - bx + c = 0:\n"
            "#\n"                                           );

    double a = 0;
	double b = 0;
	double c = 0;

    input_double ("a", &a);
    input_double ("b", &b);
    input_double ("c", &c);

    double root1 = 0;
	double root2 = 0;

    int r_count = 0;

    r_count = solve_square (a, b, c, &root1, &root2);

    switch (r_count)
    {
        case 0:        printf ("# Your equation has no roots\n");
                       break;

        case 1:        printf ("# The root of your equation is %lg\n", root1);
                       break;

        case 2:        printf ("# The roots of your equation are %lg and %lg\n", root1, root2);
                       break;

        case INFINITE: printf ("# Your equation has infinite number of roots\n");
                       break;

        default:       printf ("# Oooops... Something went wrong:\n"
                               "# main(): r_count = %d\n", r_count);
    }

    return 0;
}
