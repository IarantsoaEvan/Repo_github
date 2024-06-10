NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = client.c server.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): client server
