.DEFAULT_GOAL	:= m
UTILS			= $(addprefix utils/, sigsegv.cpp color.cpp check.cpp leaks.cpp)
PARENT_DIR		= $(shell dirname $(shell pwd))
LIBFT_PATH		= ../libft
TESTS_PATH		= tests/
MANDATORY		= abs div bzero memcpy memmove memchr memcmp isalpha isdigit \
				isascii toupper tolower strchr strrchr strncmp strnstr \
				strdup strsub strjoin strtrim strsplit strmap \
				striter memset strstr

CC = clang++
CFLAGS	= -g3 -ldl -std=c++98 -I utils/ -I$(LIBFT_PATH)
UNAME = $(shell uname -s)
VALGRIND = valgrind -q --leak-check=full

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L$(LIBFT_PATH) -lft && $(VALGRIND) ./a.out && rm -f a.out

mandatory_start:
	@tput setaf 6
	make -C $(LIBFT_PATH)
	@tput setaf 4 && echo [Mandatory]

checkmakefile:
	@ls $(LIBFT_PATH) | grep Makefile > /dev/null 2>&1 || (tput setaf 1 && echo Makefile not found. && exit 1)

m: $(MANDATORY)

clean:
	make clean -C $(LIBFT_PATH) && rm -rf a.out*

fclean:
	make fclean -C $(LIBFT_PATH) && rm -rf a.out*

.PHONY:	mandatory_start m a fclean clean
