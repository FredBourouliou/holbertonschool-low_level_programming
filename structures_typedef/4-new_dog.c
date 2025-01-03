#include <stdlib.h>
#include "dog.h"
#include "main.h"
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
/**
  * new_dog - the dog informations
  * @name: name
  * @age: age
  * @owner: owner name
  * Return: 0
  */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *cutie_dog = NULL;
int name_l = 0, own_l = 0;
if (name != NULL && owner != NULL)
{
name_l = _strlen(name) + 1;
own_l = _strlen(owner) + 1;
cutie_dog = malloc(sizeof(dog_t));
if (cutie_dog == NULL)
return (NULL);
cutie_dog->name = malloc(sizeof(char) * name_l);
if (cutie_dog->name == NULL)
{
free(cutie_dog);
return (NULL);
}
cutie_dog->owner = malloc(sizeof(char) * own_l);
if (cutie_dog->owner == NULL)
{
free(cutie_dog->name);
free(cutie_dog);
return (NULL);
}
cutie_dog->name = _strcpy(cutie_dog->name, name);
cutie_dog->owner = _strcpy(cutie_dog->owner, owner);
cutie_dog->age = age;
}
return (cutie_dog);
}
/**
  * _strlen - Returns the length of a string
  * @s: String
  * Return: String length
  */
int _strlen(char *s)
{
int c = 0;
for (; *s != '\0'; s++)
{
c++;
}
return (c);
}
/**
  * _strcpy - Copy a string
  * @dest: Destination
  * @src: Source
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, char *src)
{
int i;
for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
dest[i++] = '\0';
return (dest);
}
