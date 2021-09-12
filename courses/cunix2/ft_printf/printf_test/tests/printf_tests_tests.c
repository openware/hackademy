#include <stdlib.h>
#include "../header.h"


void test_printf_tests_test(void)
{

	ASSERT_PRINTF("Hallo world");

	ASSERT_PRINTF("%s",       "Hallo world");
	ASSERT_PRINTF("%d",       1024);
	ASSERT_PRINTF("%d",       -1024);
	ASSERT_PRINTF("%i",       1024);
	ASSERT_PRINTF("%i",       -1024);
	ASSERT_PRINTF("%c",       'x');
	ASSERT_PRINTF("%%");

	ASSERT_PRINTF("%c",       '\0');

	ASSERT_PRINTF("%+d",      1024);
	ASSERT_PRINTF("%+d",      -1024);
	ASSERT_PRINTF("%+i",      1024);
	ASSERT_PRINTF("%+i",      -1024);
	ASSERT_PRINTF("% d",      1024);
	ASSERT_PRINTF("% d",      -1024);
	ASSERT_PRINTF("% i",      1024);
	ASSERT_PRINTF("% i",      -1024);

	ASSERT_PRINTF("%1s",      "Hallo heimur");
	ASSERT_PRINTF("%1d",      1024);
	ASSERT_PRINTF("%1d",      -1024);
	ASSERT_PRINTF("%1i",      1024);
	ASSERT_PRINTF("%1i",      -1024);
	ASSERT_PRINTF("%20s",      "Hallo");
	ASSERT_PRINTF("%20d",      1024);
	ASSERT_PRINTF("%20d",      -1024);
	ASSERT_PRINTF("%20i",      1024);
	ASSERT_PRINTF("%20i",      -1024);

	ASSERT_PRINTF("%20c",      'x');

	ASSERT_PRINTF("%020d",      1024);
	ASSERT_PRINTF("%020d",      -1024);
	ASSERT_PRINTF("%020i",      1024);
	ASSERT_PRINTF("%020i",      -1024);
}
