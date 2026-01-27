#include <stdio.h>
#include <ctype.h>

double atof(char s[]) {
  
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  val = sign * val / power;

  // exponent 
  if (s[i] == 'e' || s[i] == 'E') {
    i++;

    // sign check
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;

    // find exponent
    int exp;
    for (exp = 0; isdigit(s[i]); i++)
      exp = 10.0 * exp + (s[i] - '0');

    // positive exp
    if (sign == 1)
      while (exp > 0) {
        val *= 10;
        exp--;
      }
    else
      while (exp > 0) {
        val /= 10;
        exp--;
      }
  }
  return val;
}

int main() {
    char s[] = "420e-2";
    printf("%lf\n", atof(s)); 
    return 0;
}
