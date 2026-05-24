/*Exercise 5-18. Make dcl recover from input errors.
 */

//parse the declorator 
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; ) // count '*' char
        ns++;
    
    if (tokentype != NAME && tokentype != '(') { // valid input
        printf("error: NAME expected\n");

        while (tokentype != '\n' && tokentype != EOF) // skip '\n'
            tokentype = gettoken();
        return;
    }

    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to"); // apend to out
}
