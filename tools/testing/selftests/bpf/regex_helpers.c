#include <test_progs.h>
#include "regex_helpers.h"

int compile_regex(const char *pattern, int re_flags, regex_t *re)
{
	int err;
	if (!re) {
		PRINT_FAIL("NULL re passed to compile_regex\n");
		return -1;
	}
	err = regcomp(re, pattern, re_flags);
	if (err) {
		char errbuf[512];
		regerror(err, re, errbuf, sizeof(errbuf));
		PRINT_FAIL("Can't compile regex: %s\n", errbuf);
		regfree(re);
	}
	return err;
}

int match_regex(const char *pattern, const char *str, regmatch_t *match)
{
	int err;
	regex_t re;

	err = compile_regex(pattern, 0, &re);
	if (err)
		return err;

	if (match) {
		err = regexec(&re, str, 1, match, 0);
	} else {
		err = regexec(&re, str, 0, NULL, 0);
	}

	if (err) {
		PRINT_FAIL("Can't match regex '%s'\n", pattern);
	}

	regfree(&re);
	return err;
}

