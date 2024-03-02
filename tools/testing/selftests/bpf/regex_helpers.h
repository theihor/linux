#ifndef __REGEX_HELPERS_H
#define __REGEX_HELPERS_H

#include <regex.h>

int compile_regex(const char *pattern, int re_flags, regex_t *re);
int match_regex(const char *pattern, const char *str, regmatch_t *match);

#endif

