/* Exercise 7-7. Modify the pattern finding program of Chapter 5 
 * to take its input from a set of named files or, if no files 
 * are named as arguments, from the standard input. Should the file
 * name be printed when a matching line is found?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

FILE *load(char *);
int getline(char *, size_t, FILE *);
int pattern(FILE *, char *, int, int);

int main(int argc, char **argv) {


	return 0;
}
