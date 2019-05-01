#include "acronym.h"

char *abbreviate(const char *phrase)
{
	char *acronyme = NULL;

	if (phrase != NULL && phrase[0] != '\0')
		{ acronyme = calloc(strlen(phrase), sizeof(char)); }
	else
		{ return (NULL); }

	if (acronyme == NULL)
		{ return (NULL); }

	for (int i = 0, j = 0; phrase[i]; i++) {
		if (isalpha(phrase[i]) != 0 && (i == 0 || phrase[i - 1] == ' ' || phrase[i -1] == '-')) {
			if (islower(phrase[i]) != 0)
				{ acronyme[j] = phrase[i] - 32; }
			else
				{ acronyme[j] = phrase[i]; }
			j++;
		}
	}

	return (acronyme);
}
