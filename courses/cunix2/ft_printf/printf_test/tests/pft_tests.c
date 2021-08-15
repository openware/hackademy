#include "../header.h"

void test_pft_nacked(void)
{
	ASSERT_PRINTF("hello, world!");
	ASSERT_PRINTF("");
	ASSERT_PRINTF("\t\n\r\v\f\n");
}

void test_pft_percent(void)
{
	ASSERT_PRINTF("%%");
	ASSERT_PRINTF("%5%");
	ASSERT_PRINTF("%-5%");
	ASSERT_PRINTF("%05%");
	ASSERT_PRINTF("%-05%");
}

void test_pft_nocrash(void)
{
	static int ncm_p = 5;

	ASSERT_PRINTF("%-x", 42);
	ASSERT_PRINTF("%-c", 'a');
	ASSERT_PRINTF("%-s", "hello");
	ASSERT_PRINTF("%-s", NULL);
	ASSERT_PRINTF("%23s", NULL);
	ASSERT_PRINTF("%s", NULL);
}

void test_pft_string(void)
{
	ASSERT_PRINTF("hello, %s.", "gavin");
	ASSERT_PRINTF("%s", "testing testing");
	ASSERT_PRINTF("%s%s", "hello", "world");
	ASSERT_PRINTF("..%s stuff %s", "a", "b");
	ASSERT_PRINTF("this %s is empty", "");
	ASSERT_PRINTF("this %s is %s", "hello", "");
	ASSERT_PRINTF("this %s is %s", "", "hello");
	ASSERT_PRINTF("%s%s%s", "1", "2", "3's a charm");

	ASSERT_PRINTF("%32s", "abc");
	ASSERT_PRINTF("%16s", "nark nark");
	ASSERT_PRINTF("%5s", "goes over");
	ASSERT_PRINTF("%-32s", "abc");
	ASSERT_PRINTF("%-16s", "nark nark");
	ASSERT_PRINTF("%-5s", "goes over");
	ASSERT_PRINTF("hello, %s.", NULL);
	ASSERT_PRINTF("%s", NULL);
	ASSERT_PRINTF("%32s", NULL);
	ASSERT_PRINTF("%2s", NULL);
	ASSERT_PRINTF("%-32s", NULL);
	ASSERT_PRINTF("%-16s", NULL);
	ASSERT_PRINTF("%-3s", NULL);

	static char *s_hidden = "hi low\0don't print me lol\0";
	ASSERT_PRINTF("%s", s_hidden);
	ASSERT_PRINTF("%3s", s_hidden);
	ASSERT_PRINTF("%9s", s_hidden);
}

void test_pft_int_i(void)
{
	ASSERT_PRINTF("this %i number", 17);
	ASSERT_PRINTF("this %i number", -267);
	ASSERT_PRINTF("this %i number", 0);
	ASSERT_PRINTF("%i", 3);
	ASSERT_PRINTF("%i", -1);
	ASSERT_PRINTF("%i", 0);
	ASSERT_PRINTF("this %d number", 17);
	ASSERT_PRINTF("this %d number", -267);
	ASSERT_PRINTF("this %d number", 0);
	ASSERT_PRINTF("%i",  2147483647);
	ASSERT_PRINTF("%i", (int)(-2147483678));

	ASSERT_PRINTF("%7i", 33);
	ASSERT_PRINTF("%7i", -14);
	ASSERT_PRINTF("%3i", 0);
	ASSERT_PRINTF("%5i", 52625);
	ASSERT_PRINTF("%5i", -2562);
	ASSERT_PRINTF("%4i", 94827);
	ASSERT_PRINTF("%4i", -2464);
	ASSERT_PRINTF("%-7i", 33);
	ASSERT_PRINTF("%-7i", -14);
	ASSERT_PRINTF("%-3i", 0);
	ASSERT_PRINTF("%-5i", 52625);
	ASSERT_PRINTF("%-5i", -2562);
	ASSERT_PRINTF("%-4i", 94827);
	ASSERT_PRINTF("%-4i", -2464);
	ASSERT_PRINTF("%05i", 43);
	ASSERT_PRINTF("%07i", -54);
	ASSERT_PRINTF("%03i", 0);
	ASSERT_PRINTF("%03i", 634);
	ASSERT_PRINTF("%04i", -532);
	ASSERT_PRINTF("%04i", -4825);
}
