/*!
	\file
	\brief Header file with descriprion of functions
	\author SaintAleksei
	\date September 2021
	
	This file contains:
		Some defines;
		The defenition of all functions;
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>

//-----------------------------------------------------------------------------

#define INFINITE -1
#define INFELICITY 1E-6
#define BUF_SIZE 64

//-----------------------------------------------------------------------------

/*! 
	\brief This function solves linear equation (ax + b = 0)
	\param[in] a The first coefficient of the equation
	\param[in] b The second coefficient of the equation
	\param[in,out] root_ad A pointer to a variable that will store root of the equation
	\return Count of roots (0, 1 or special defined constant INFINITE (-1) )
*/

int solve_linear             (double a, double a, double* root_ad);

/*! 
	\brief This function solves square equation (ax^2 + bx + c = 0)
	\param[in] a The first coefficient of the equation
	\param[in] b The second coefficient of the equation
	\param[in] c The third coefficient of the equation
	\param[in,out] root1_ad A pointer to a variable that will store the first root of the equation
	\param[in,out] root2_ad A pointer to a variable that will store the second root of the equation
	\return Count of roots (0, 1, 2 or special defined constant INFINITE (-1) )
*/

int solve_square             (double a, double b, double c, double* root1_ad, double* root2_ad);

/*! 
	\brief This function responsible for entering double value
	\param[in] name Name of variable, that will store the number entered
	\param[in,out] value Pointer to a variable that will store the number entered 
	\return Zero on success (this function works untill success)
*/

int input_double             (const char* name, double* value);

/*! 
	\brief This function comparing double value with zero according to INFELICITY (1E-6)
	\param[in] value Double value
	\return Zero (value == 0) or not zero (value != 0)
*/

int is_zero                  (double value);

/*! 
	\brief This function make test of function solve_square, that solve square equation (ax^2 + bx + c), and print everythig in stdout
	\param[in] a The first coefficient of the equation
	\param[in] b The second coefficient of the equation
	\param[in] c The third coefficient of the equation
	\parem[in] exp_rcount Expected count of roots 
	\parem[in] exp_root1 Expected value of the first root (zero if nothing expected)
	\parem[in] exp_root2 Expected value of the second root (zero if nothing expected)
	\return One in case of success and zero otherwise
*/

int solve_square_test        (double a, double b, double c, int exp_rcount, double exp_root1, double exp_root2);

/*!
	\brief This function calls solve_square_test many times with different parameters and print everythin in stdout
	\return Zero
*/
int run_solve_square_testing ();
