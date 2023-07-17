#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *init_dog - initializes function
 *@struct dog: varible
 *@name: variable
 *@age: variable
 *@owner: variable
 *Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
