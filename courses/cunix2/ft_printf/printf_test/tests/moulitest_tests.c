#include <limits.h>
#include "../header.h"


void test_moulitest_00(void)
{
	ASSERT_PRINTF("This is a simple test.");
	ASSERT_PRINTF("This is a simple test.\nSecond sentence.\n");
	ASSERT_PRINTF("");
	ASSERT_PRINTF("\n");
}

void test_moulitest_01(void)
{
	ASSERT_PRINTF("%s", "abc");
	ASSERT_PRINTF("111%s333", "222");
	ASSERT_PRINTF("%s333", "222");
	ASSERT_PRINTF("111%s", "222");
	ASSERT_PRINTF("{%s}", "");
}

void test_moulitest_02(void)
{
	ASSERT_PRINTF("111%s333%s555", "222", "444");
	ASSERT_PRINTF("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	ASSERT_PRINTF("%s%s%s%s%s", "1", "2", "3", "4", "5");
}

void test_moulitest_03(void)
{
	ASSERT_PRINTF("%d", 42);
	ASSERT_PRINTF("%d", -42);
	ASSERT_PRINTF("before %d after", 42);
	ASSERT_PRINTF("%d%d%d%d%d", 1, -2, 3, -4, 5);
	ASSERT_PRINTF("a%db%dc%dd", 1, -2, 3);
	ASSERT_PRINTF("%d", INT_MAX);
	ASSERT_PRINTF("%d", INT_MIN);
}

void test_moulitest_05(void)
{
	ASSERT_PRINTF("%%");
	ASSERT_PRINTF("aa%%bb");
	ASSERT_PRINTF("%%%%%%%%%%");
	ASSERT_PRINTF(".%%.%%.%%.%%.%%.%%.%%.%%.");
}

void test_moulitest_09(void)
{
	ASSERT_PRINTF("%i", 42);
	ASSERT_PRINTF("%i", -42);
	ASSERT_PRINTF("before %i after", 42);
	ASSERT_PRINTF("%i%i%i%i%i", 1, -2, 3, -4, 5);
	ASSERT_PRINTF("a%ib%ic%id", 1, -2, 3);
}

void test_moulitest_16(void)
{
	ASSERT_PRINTF("%c", 'c');
	ASSERT_PRINTF("%c%c", '4', '2');
	ASSERT_PRINTF("%c", 0);
}

void test_moulitest_50(void)
{
	ASSERT_PRINTF("{%10d}", 42);
	ASSERT_PRINTF("{%4d}", 10000);
	ASSERT_PRINTF("{%30d}", 10000);
	ASSERT_PRINTF("{%10d}", -42);
	ASSERT_PRINTF("{%3c}", 0);
	ASSERT_PRINTF("{%-13d}", 123);
	ASSERT_PRINTF("{%-13s}", "kek");
}

void test_moulitest_51(void)
{
	ASSERT_PRINTF("{%-10d}", 42);
	ASSERT_PRINTF("{%-4d}", 10000);
	ASSERT_PRINTF("{%-30d}", 10000);
}

void test_moulitest_52(void)
{
	ASSERT_PRINTF("{%010d}", -42);
	ASSERT_PRINTF("{%04d}", 10000);
	ASSERT_PRINTF("{%030d}", 10000);
}

void test_moulitest_61(void)
{
	ASSERT_PRINTF("%+d", 42);
	ASSERT_PRINTF("%+d", -42);
	ASSERT_PRINTF("%+i", 42);
	ASSERT_PRINTF("%+i", -42);
	ASSERT_PRINTF("% d", 9999);
	ASSERT_PRINTF("% d", -9999);
	ASSERT_PRINTF("% i", 9999);
	ASSERT_PRINTF("% i", -9999);
}

void test_moulitest_69(void)
{
	ASSERT_PRINTF("{%+03d}", 0);
	ASSERT_PRINTF("{% 03d}", 0);
	ASSERT_PRINTF("{%+03d}", 12);
	ASSERT_PRINTF("{%+03d}", 123456);
}
