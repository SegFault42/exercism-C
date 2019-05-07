#include "rna_transcription.h"

char *to_rna(const char *dna)
{
	char	*rna = NULL;

	if (dna == NULL || dna[0] == '\0')
		{ return (NULL); }

	rna = strdup(dna);
	if (rna == NULL)
		{ return (NULL); }

	for (int idx = 0; rna[idx]; idx++) {
		if (rna[idx] == 'G') rna[idx] = 'C';
		else if (rna[idx] == 'C') rna[idx] = 'G';
		else if (rna[idx] == 'T') rna[idx] = 'A';
		else if (rna[idx] == 'A') rna[idx] = 'U';
		else {
			free(rna);
			return (NULL);
		}
	}

	return (rna);
 }
