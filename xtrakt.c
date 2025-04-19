#include <stdio.h>
#define MAXLENGTH 12000
#define DELIMITER '\"'

int getString(char []);
int isRelativeURL(char []);
enum {FALSE, TRUE};

int main(int argc, char *argv[])
{
    char url[MAXLENGTH];
    /* Get the string between the delimeter as a possible URL
     * if the first two character of the string are "./" print the string.
     *	    Do not print if the string is "./"
     */
    while (getString(url) != EOF) { 
	if (isRelativeURL(url))
	    printf("%s\n", url);
    }
    return 0;
}

int getString(char s[])
{
    int c, i;

    while((c = getchar()) != EOF) {
	if (c == DELIMITER) {
	    /* start saving the characters */
	    for (i = 0; (c = getchar()) != DELIMITER && c != EOF; i++)
		s[i] = c;
	    s[i] = '\0';
	    if (c == EOF)
		return EOF;
	    return i;
	}
    }
    return EOF;
}

int isRelativeURL(char s[])
{
    if (s[0] == '.' && s[1] == '/' && s[2] != '\0')
	return TRUE;
    else if (s[0] == '/' && s[1] != '\0')
	return TRUE;
    else
	return FALSE;
}
