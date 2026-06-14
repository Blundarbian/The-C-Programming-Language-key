/* Exercise 8-6. The standard library function calloc(n,size) 
 * returns a pointer to n objects of size size, with the storage 
 * initialized to zero. Write calloc, by calling malloc or 
 * by modifying it.
 */

#include <stdio.h>
#include <stdlib.h>

void *ccalloc(size_t, size_t);

int main() {

	float *list = (float *)ccalloc(10, sizeof(float));
	for (int i = 0; i < 10; i++)
		list[i] = i * i;

	printf("[ ");
	for (int i = 0; i < 10; i++)
		printf("%.1f ", list[i]);
	printf("]\n");

	free(list);
	return 0;
}


void *ccalloc(size_t n, size_t size) {
	void *ptr;
	if ((ptr = malloc(n * size)) == NULL)
		return NULL;
	return ptr;
}
