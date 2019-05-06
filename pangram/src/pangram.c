#include "pangram.h"

bool	is_pangram(const char *sentence)
{
	char alphabet[] = "abcdefghijklmnopqrstuwxyz";
	char *copy = NULL;

	if (sentence == NULL || sentence[0] == '\0')
		{ return (false); }

	copy = strdup(sentence);
	if (copy != NULL) {
		for(int i = 0; copy[i]; i++)
			{ copy[i] = tolower(copy[i]); }
	}

	for (int i = 0; alphabet[i]; i++) {
		if (strchr(copy, alphabet[i]) == NULL) {
			free(copy);
			return (false);
		}
	}

	free(copy);
	return (true);
}
