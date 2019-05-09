#include "beer_song.h"

#define BOTTLE	str[5]
#define BOTTLES	str[4]

void	verse(char *buff, int n)
{
	char *str[] = {
		" of beer on the wall, ",
		" of beer.\nTake",
		" of beer on the wall.\n",
		" no more",
		" bottles",
		" bottle",
		" one",
		" it",
		" down and pass it around,",
		NULL
	};

	if (n > 2)
		{ sprintf(buff, "%d%s%s%d%s%s%s%s %d%s%s", n, BOTTLES, str[0], n, BOTTLES, str[1], str[6], str[8], n -1, BOTTLES, str[2]); }
	else if (n == 2)
		{ sprintf(buff, "%d%s%s%d%s%s%s%s %d%s%s", n, BOTTLES, str[0], n, BOTTLES, str[1], str[6], str[8], n -1, BOTTLE, str[2]); }
	else if (n == 1)
		{ sprintf(buff, "%d%s%s%d%s%s%s%s%s%s%s", n, BOTTLE, str[0], n, BOTTLE, str[1], str[7], str[8], str[3], BOTTLES, str[2]); }
	else if (n == 0) {
		sprintf(buff, "No more bottles of beer on the wall, no more bottles of beer.\n"
       "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
	}
}

void	sing(char *buff, int n1, int n2)
{
	int len = 0;

	memset(buff, 0, 1024);

	for (; n1 >= n2; n1--) {
		len = strlen(buff);
		verse(&buff[len], n1);
		if (n1 != n2)
			strcat(buff, "\n");
	}
}
