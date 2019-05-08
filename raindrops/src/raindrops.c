#include "raindrops.h"

void	convert(char *buff, int n)
{
	if (!(n % 3)) strcat(buff, "Pling");
	if (!(n % 5)) strcat(buff, "Plang");
	if (!(n % 7)) strcat(buff, "Plong");
	if (strlen(buff) == 0) sprintf(buff, "%d", n);
}
