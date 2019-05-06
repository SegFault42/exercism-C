#define _POSIX_C_SOURCE 200809L
#include "word_count.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static void	free_array(char **array)
{
	for (int i = 0; array[i]; i++) {
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

static char	**split_string(const char *str, char *limit)
{
	char	*ptr = NULL;
	char	**cmd = NULL;
	size_t	idx = 0;
	char	*string = NULL;

	string = strdup(str);

	// replace all non alpha with ' '
		for (int i = 0; string[i]; i++) {
			if (!isalpha(string[i]) && !isalnum(string[i]))
				{ string[i] = ' '; }
		}

	ptr = strtok(string, limit);

	while (ptr) {
		cmd = (char **)realloc(cmd, ((idx + 1) * sizeof(char *)));
		cmd[idx] = strdup(ptr);

		ptr = strtok(NULL, limit);
		++idx;
	}

	free(string);
	string = NULL;

	cmd = (char **)realloc(cmd, ((idx + 1) * sizeof(char *)));
	cmd[idx] = NULL;

	return (cmd);
}

int word_count(const char *input_text, word_count_word_t *words)
{
	char	**array = NULL;
	int 	nb_elem = 0;

	array = split_string(input_text, " ");
	if (array == NULL)
		{ return (-1); }

	for (int i = 0; array[i]; i++) {
		if (array[i][0] == '\0')
			{ continue ;}

		strcpy(words->text, array[i]);
		words->count = 0;

		for (int j = 0; array[j]; j++) {
			if (!strcmp(words->text, array[j])) {
				memset(array[j], 0, strlen(array[j]));
				words->count += 1;
			}
		}

		/*printf("[%s = %d]\n", words->text, words->count);*/

		words++;
		nb_elem++;
	}
	/*printf("[%d]\n", nb_elem);*/

	free_array(array);

	return (nb_elem);
}


// split la string sur les blanc
// Comptez le nombre de mot different pour la valeur de retour
// parcourir le tableau et comptez le nombre de string identique
// remplacer cette string par un ""
//
// ["hi", "hello", "hi", "lol"]
//
//
