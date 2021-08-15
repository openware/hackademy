#CLEANEXTS = o a

#OUTPUTFILE = libft.a
#INSTALLDIR = ../binaries

#Default target
#.PHONY: all

#all: $(OUTPUTFILE)

#$(OUTPUTFILE): *.o #%.o
#	ar ru $@ $^
#	ranlib $@

#.PHONY: install

#install:
#	mkdir -p $(INSTALLDIR)
#	cp -p $(OUTPUTFILE) $(INSTALLDIR)

#.PHONY: clean
#clean:
#	for file in $(CLEANEXTS); do rm -f *.$$file; done

#*.o:
#SRCS: := $(wildcard ./*.c)
SRCS := $(shell find . -name '*.c')
OBJS := $(SRCS:.c=.o)

CC := gcc

CFLAGS += -Iinclude -Wall -Wextra -Werror -g

all: *.o libft.a
all: ##ft_abs.o ft_div.o libft.a

./%.o: %.c
	$(CC) $(CFLAGS) $(OBJS) -c $< -o $@
#%.c:
#	$(CC) $(CFLAGS) $(OBJS)

libft.a: #ft_abs.o ft_div.o #*.o
	ar rcs libft.a #ft_abs.o ft_div.o#*.o
libs: libft.a

clean:
	rm -f *.o *.a
