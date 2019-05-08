#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	hash
{
	char		nucleotide;
	size_t		count;
}				s_hash;

char	*count(const char *);

#endif
