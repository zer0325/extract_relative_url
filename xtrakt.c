#include <stdio.h>
#define MAXLENGTH 1000
#define DELIMITER '\"'

int getString(char []);

int main(int argc, char *argv[])
{
    char url[MAXLENGTH];
    printf("debug:\n");
    /* Get the string between the delimeter as a possible URL
     * if the first two character of the string are "./" print the string.
     *	    Do not print if the string is "./"
     */
    while (getString(url) > 0) { 
	if (url[0] == '.' && url[1] == '/' && url[2] != '\0')
	    printf("%s\n", url);
	else if (url[0] == '/' && url[1] != '\0')
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
	    return i;
	}
    }
    return 0;
}
