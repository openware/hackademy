#include <stdio.h>
#include "header.h"
#include "tests/tests.h"

int pid;
int pid2;
bool signaled;
bool origin_signaled = false;
bool user_signaled = false;
int origin_ret;
int user_ret;
char *origin_buf;
char *user_buf;

struct timeval timeout;
fd_set input_set;
int    timeout_pipe[2];
int    fd_read_num;

char fd_buf[10];

int main(int argc, char **argv)
{
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	if (pipe(timeout_pipe) == -1)
		return (1);

	(void)argc;
	(void)argv;

	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	test_pft_nacked();
	test_pft_percent();
	test_pft_nocrash();
	test_pft_string();
	test_pft_int_i();

	test_moulitest_00();
	test_moulitest_01();
	test_moulitest_02();
	test_moulitest_03();
	test_moulitest_05();
	test_moulitest_09();
	test_moulitest_16();
	test_moulitest_50();
	test_moulitest_51();
	test_moulitest_52();
	test_moulitest_61();
	test_moulitest_69();

	test_printf_tests_test();

	return 0;
}
