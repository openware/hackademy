NAME = libft.a
CC := gcc
RM := rm -rf

SRC = ft_bzero.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isalpha.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strjoin.c \
	  ft_strmap.c \
	  ft_strncmp.c \
	  ft_strsub.c \
	  ft_strtrim.c

CCFLAGS = -Wall -Iinclude -Wextra -Werror -g -std=c99
OBJS := $(SRC:.c=.o)
all: $(NAME)
$(NAME): 	$(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
clean:	clean
	$(RM) $(NAME)

re: fclean all
