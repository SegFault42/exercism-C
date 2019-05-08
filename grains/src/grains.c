#include "grains.h"

size_t	square(size_t n)
{
	return (n > 64 ? 0 : pow(2, n-1));
}

size_t	total(void)
{
	return ((size_t)pow(2, 64));
}
