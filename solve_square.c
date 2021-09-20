#include "solve_square.h"

int solve_linear (double a, double b, double* root_ad)
{
	if (!root_ad)
		return 0;	

    if (is_zero (a) && is_zero (b))
        return INFINITE;

    if (is_zero (a) && !is_zero (b))
        return 0;

    *root_ad = -b / a;

    return 1;
}

int solve_square (double a, double b, double c, double* root1_ad, double* root2_ad)
{
	if (!root1_ad || !root2_ad)
		return 0;

    if (is_zero (a))
        return solve_linear (b, c, root1_ad);

    double discr = (b * b) - (4 * a * c);

    if (is_zero (discr))
    {
        *root1_ad = -b / (2 * a);

        return 1;
    }

    if (discr < 0)
        return 0;

    *root1_ad = (-b + sqrt (discr) / (2 * a));
    *root2_ad = (-b - sqrt (discr) / (2 * a));

    return 2;
}

int input_double (const char* name, double* value)
{
    printf ("# %s = ", name);

	char bufer[BUF_SIZE] = {};

	fgets (bufer, BUF_SIZE, stdin);

    while (sscanf (bufer, "%lg", value) != 1)
    {
        printf ("# Invalid input: enter a real numbers:\n"
				"# %s = ", name);

		fgets (bufer, BUF_SIZE, stdin);
	}

    return 0;
}

int is_zero (double a)
{
    return fabs (a - 0) <= INFELICITY ? 1 : 0;
}

//-----------------------------------------------------------------------------

#define TESTS_COUNT 4

int run_solve_square_testing ()
{
	printf ("Running test of solve_square ()...\n");

	int ok_count = 0;

	ok_count += solve_square_test (1, 2, 1, 1, -1, 0);
	ok_count += solve_square_test (1, 2, 1, 1, -1, 0);
	ok_count += solve_square_test (1, 0, -4, 2, -2, 2);
	ok_count += solve_square_test (0, 2, 4, 1, -2, 0);

	printf ("Result: %d of %d tests are passed.\n", ok_count, TESTS_COUNT);

	return 0;
}

int solve_square_test (double a, double b, double c, int exp_rcount, double exp_root1, double exp_root2)
{
	double root1 = 0;
	double root2 = 0;

	int rcount = solve_square (a, b, c, &root1, &root2);	

	if (root1 > root2 && rcount == 2)
	{
		double buf = root1;
		root1 = root2;
		root2 = buf;
	}

	if (rcount != exp_rcount || !is_zero (exp_root1 - root1) || !is_zero (exp_root2 - root2) )
	{
		printf ("TEST [a = %lg, b = %lg, c = %lg] FAILED: ---  {ERROR}\n"
				"	Expected: rcount = %d, root1 = %lg, root2 = %lg\n"
				"	Result:   rcount = %d, root1 = %lg, root2 = %lg\n", a, b, c, exp_rcount, exp_root1, exp_root2, rcount, root1, root2);

		return 0;
	}
	else
	{
		printf ("TEST [a = %lg, b = %lg, c = %lg] PASSED  ---  {OK}\n", a, b, c);

		return 1;
	}
}
