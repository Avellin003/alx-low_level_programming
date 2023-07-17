#include <stdio.h>
#include "dog.h"
/**
 * print_dog - pritns infos on dog
 * @Name: name of dog
 * @Age: age of the dog
 * @Ownner: owners's name
 * Return: void if sucess or Nil if fail
 */
void print_dog(struct dog *d)
{
	if (d)
	{
		if (d->name == NULL)
			printf("Name: (nil)\n");

		else
			printf("Name: %s\n", d->name);

		printf("Age: %f\n", d->age);

		if (d->owner == NULL)
			printf("Owner: (nil)\n");

		else
		printf("Owner: %s\n", d->owner);
	}
}
