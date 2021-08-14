CC		:= gcc
RM		:= rm -rf
LDFLAGS	:= -Llib
CFLAGS	:= -Iinclude -Wall -Wextra -Werror -g
SRCS	:= $(wildcard src/*.c)
OBJS	:= $(SRCS:.c=.o)
NAME	:= hackbox


all:		fclean $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

debug:		$(NAME)
				valgrind -v --leak-check=full --track-origins=yes ./$(NAME)

