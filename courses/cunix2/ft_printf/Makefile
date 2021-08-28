CC		:= gcc
RM		:= rm -rf
LDFLAGS	+= -Llib
CFLAGS	+= -std=c99 -Iinclude -Wall -Wextra -Werror -g -c
SRCS	:= $(wildcard src/*.c)
OBJS	:= $(SRCS:.c=.o)
LIB_NAME	:= libftprintf.a
STYLE50	:= ~/.local/bin/style50


printf:		fclean $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o a.out

bonus:		all

all:		fclean $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)
			@ar rcs $(LIB_NAME) $(OBJS)

checkstyle:	
			$(STYLE50) $(SRCS)

fclean:
			$(RM) $(OBJS) $(LIB_NAME)
