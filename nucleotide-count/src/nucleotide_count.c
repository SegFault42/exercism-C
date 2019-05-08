#include "nucleotide_count.h"

char	*count(const char *strand)
{
	s_hash	hash[4] = {{0}};
	int		error = 0, length = 0, ret = 0;
	char	*buffer = NULL;

	hash[0].nucleotide = 'A';
	hash[1].nucleotide = 'C';
	hash[2].nucleotide = 'G';
	hash[3].nucleotide = 'T';

	for (int idx = 0; strand[idx]; idx++) {
		if (strand[idx] == 'A') hash[0].count++;
		else if (strand[idx] == 'C') hash[1].count++;
		else if (strand[idx] == 'G') hash[2].count++;
		else if (strand[idx] == 'T') hash[3].count++;
		else {
			error = -1;
			break;
		}
	}

	if (error == -1)
		{ return (calloc(0, sizeof(char))); }

	// calculate how many byte to allocate
	for (int idx = 0; idx < 4; idx++)
		{ length += snprintf(NULL, 0, "%c:%ld ", hash[idx].nucleotide, hash[idx].count); }

	buffer = calloc(length, sizeof(char));
	if (buffer == NULL)
		{ return (NULL); }

	// fill buff
	for (int idx = 0; idx < 4; idx++) {
		ret += snprintf(&buffer[ret], length, "%c:%ld ", hash[idx].nucleotide, hash[idx].count);
	}

	// erase last space with null terminated string
	buffer[length -1] = '\0';

	return (buffer);
}
