
CC				:= gcc

RM				:= rm -rf

CFLAGS		    	+= -Iinclude -Wall -Wextra -Werror -g

LDFLAGS		    	+= -Llib

SRCS				:= $(wildcard src/*.c)

OBJS				:= $(SRCS:.c=.o)

NAME				:= strlen_test

all:				$(NAME)

$(NAME):			$(OBJS)
						$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  $(LDFLAGS)  

clean:
				$(RM) $(OBJS)

fclean:		 		    clean
				$(RM) $(NAME)

re: 				fclean all

test:				re
				@(./$(NAME) && echo "Test success" || echo "Test Fails")

debug:				$(NAME)
				valgrind -v --leak-check=full --track-origins=yes ./$(NAME)
