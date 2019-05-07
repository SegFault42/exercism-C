#include "hamming.h"

int	compute(char *strand1, char *strand2)
{
	int distance = 0;

	if (strand1 == NULL || strand2 == NULL || strlen(strand1) != strlen(strand2))
		{ return (-1); }

	for (int idx = 0; strand1[idx]; idx++) {
		if (strand1[idx] != strand2[idx])
			{ distance++; }
	}

	return (distance);
}
