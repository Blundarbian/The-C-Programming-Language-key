#include <stdio.h>
#include <limits.h>

int main() {
	
    printf("\n%-15s %10d\n",  "char bits",      CHAR_BIT);
    printf("%-15s %10d\n",    "char min",       SCHAR_MIN);
    printf("%-15s %10u\n",    "char unsigned",  UCHAR_MAX);
    printf("%-15s %10d\n",    "char short",     SCHAR_MAX);
    
    printf("%-15s %10d\n",    "int signed",     INT_MAX);
    printf("%-15s %10d\n",    "int min",        INT_MIN);
    printf("%-15s %10u\n",    "int unsigned",   UINT_MAX);
    
    printf("%-15s %10ld\n",   "long signed",    LONG_MAX);
    printf("%-15s %10ld\n",   "long min",       LONG_MIN);
    printf("%-15s %10lu\n",   "long unsigned",  ULONG_MAX);

    return 0;
}
	

