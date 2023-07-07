#include "main.h"
/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: value to raise
 * @y: power to raise
 *Return: -1 if the power is less than 0
 *1 if the power is equal to 0 else return the power number
 */
int _pow_recursion(int x, int y)
{
	if (y > 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
