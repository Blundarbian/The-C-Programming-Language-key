/* Exercise 5-20. Expand dcl to handle declarations 
 * with function argument types, qualifiers like const,
 * and so on.
 */

void dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();

		if (tokentype != ')')
			printf("error: no closing ')'\n");
	} else if (tokentype == NAME) {
		strcpy(name, token);
	} else {
		printf("error: NAME not found\n");
		return;
	}

	while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {

		if (type == PARENS) {
			strcat(out, " func return");
		} else if (type == BRACKETS) {
			strcat(out, " arr");
			strcat(out, token);
			strcat(out, " of");
		} else if (type == '(') {
			strcat(out, " func expects ");

			while ((type = gettoken()) != ')' && type != EOF) {
				strcat(out, token);
				strcat(out, " ");
			}
			strcat(out, " returns");
		}
	}
}





