#include <limits.h>
#include "header.h"

int main()
{
	ft_printf("This is a simple test.");
	ft_printf("This is a simple test.\nSecond sentence.\n");
	ft_printf("");
	ft_printf("\n");
	ft_printf("%s", "abc");
	ft_printf("111%s333", "222");
	ft_printf("%s333", "222");
	ft_printf("111%s", "222");
	ft_printf("{%s}", 0);
	ft_printf("{%s}", "");
	ft_printf("111%s333%s555", "222", "444");
	ft_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	ft_printf("%d", 42);
	ft_printf("%d", -42);
	ft_printf("before %d after", 42);
	ft_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	ft_printf("a%db%dc%dd", 1, -2, 3);
	ft_printf("%d", INT_MAX);
	ft_printf("%d", INT_MIN);
	ft_printf("%p", &strlen);
	ft_printf("%p", 0);
	ft_printf("%%");
	ft_printf("aa%%bb");
	ft_printf("%%%%%%%%%%");
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	ft_printf("%");
	ft_printf("{% %}");
	ft_printf("%i", 42);
	ft_printf("%i", -42);
	ft_printf("before %i after", 42);
	ft_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	ft_printf("a%ib%ic%id", 1, -2, 3);
	ft_printf("%");
	ft_printf("%5");
	ft_printf("%05");
	ft_printf("%-05");
	ft_printf("%-5");
	ft_printf("%s", "testing testing");
	ft_printf("%s%s", "hello", "world");
	ft_printf("..%s stuff %s", "a", "b");
	ft_printf("this %s is empty", "");
	ft_printf("this %s is %s", "hello", "");
	ft_printf("this %s is %s", "", "hello");
	ft_printf("%s%s%s", "1", "2", "3's a charm");
	ft_printf("%32s", "abc");
	ft_printf("%16s", "nark nark");
	ft_printf("%5s", "goes over");
	ft_printf("%-32s", "abc");
	ft_printf("%-16s", "nark nark");
	ft_printf("%-5s", "goes over");
	ft_printf("t1 %050d\n", 10);
}
