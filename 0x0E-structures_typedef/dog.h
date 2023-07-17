#ifndef DOG_H
#define DOG_H
void init_dog(struct dog *d, char *name, float age, char *owner);
/**
 *struct dog - prints dog's id
 *@name: dog's name
 *@age: dog's age
 *@owner: dog's owner
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;
#endif
