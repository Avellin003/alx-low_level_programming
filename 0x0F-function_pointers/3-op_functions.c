#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * op_add - function
  * @a: argument
  * @b: argument
  * Return: 0 if success
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - function substracts
  * @a: argument
  * @b: argument
  *
  * Return: 0 if success
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - function multiplies
  * @a: argument
  * @b: argument
  * Return: 0 if success
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  * op_div - function divides
  * @a: argument
  * @b: argument
  * Return: 0 if success
  */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
  * op_mod - function modulus
  * @a: argument
  * @b: argument
  *
  * Return: 0 if success
  */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
