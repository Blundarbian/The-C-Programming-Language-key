/* Exercise 5-19. Modify undcl so that it does not 
 * add redundant parentheses to declarations.
 */

// undcl : convert word to descriptions to declarations
int main() {

	int type, c1, c2;
	char temp[MAXTOKEN];
	char *pf = "(*%s)";
	char *df = "*s%s";

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') {
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				char *sf = df;
				c1 = getchar();
				c2 = getchar();

				if (c1 == ' ' && (c2 == '(' || c2 == '[')) 
					sf = pf;

				ungetch(c2);
				ungetch(c1);
				sprintf(temp, sf, out);
				strcpy(out, temp);

			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		}
		printf("%s\n", out);
	}
	return 0;
}
