#include <stdio.h>

#define swap(t, x, y) \
{\
	t temp = x;\
	x = y;\
	y = temp;\
}

int main(void) {

	int x = 321;
	int y = 9;
	printf("%d, %d\n", x, y);
	swap(int, x, y);
	printf("%d, %d\n", x, y);

	float i = 1.12;
	float j = 932.12;
	printf("%f, %f\n", i, j);
	swap(float, i, j);
	printf("%f, %f\n", i, j);


	return 0;
}
