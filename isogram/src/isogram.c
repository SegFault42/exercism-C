#include "isogram.h"

bool	is_isogram(const char phrase[])
{
	if (phrase == NULL)
		{ return (false); }

	for (int letter = 'a'; letter <= 'z'; letter++) {
		for (int i = 0, count = 0; phrase[i]; i++) {
			if (letter == phrase[i] || (isupper(phrase[i]) && letter == phrase[i] + 32))
				{ count++; }
			if (count == 2)
				{ return (false); }
		}
	}

	return (true);
}
