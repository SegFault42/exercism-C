#ifndef PANGRAM_H
#define PANGRAM_H

#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_pangram(const char *sentence);

#endif
