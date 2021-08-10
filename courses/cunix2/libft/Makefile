CC					:= gcc
RM					:= rm -rf
LDFLAGS		    	+= -Llib
CFLAGS		    	+= -std=c99 -Iinclude -Wall -Wextra -Werror -g -c
SRCS				:= $(wildcard src/*.c)
OBJS				:= $(SRCS:.c=.o)
LIB_NAME			:= libft.a
STYLE50				:= ~/.local/bin/style50

all:		    clean $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)
				@ar rcs $(LIB_NAME) src/*.o
				@$(STYLE50) $(SRCS) &>/dev/null && echo "LOOKS GOOD!!!"

clean:
				$(RM) $(OBJS) $(LIB_NAME)
