#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main() {
  char s[] = "this is creazy or ";

  char t[] = "or";

  printf("%d\n", strrindex(s, t));
  
  return 0;
}

int strrindex(char s[], char t[]) {
    int i, j, k;
    int slen = strlen(s);
    int tlen = strlen(t);

    if (tlen == 0) return -1;

    for (i = slen - tlen; i >= 0; i--) {
        for (j = i, k = 0; k < tlen && s[j] == t[k]; j++, k++)
            ;
        
        if (k == tlen)
            return i;
    }
    return -1;
}
