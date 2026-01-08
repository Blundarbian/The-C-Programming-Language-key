#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEPS 20

float fahr_conv(float fahr);

float fahr_conv(float fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}

int main()
{
  int fahr = LOWER;

  printf("---Fahr to Cel---\n");

  while (fahr <= UPPER)
    {
      printf("%3d   %3.1f\n", fahr, fahr_conv(fahr));
      fahr += STEPS;
    }

  return 0;
}
