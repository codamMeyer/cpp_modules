CC=g++
CFLAGS= -Wall -Werror -Wextra -std=c++98

NAME=zombieHorde

HEADER_FILES = 		\
	Zombie.hpp		\

SRC_FILES=			\
	Zombie.cpp		\
	ZombieHorde.cpp \

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES) main.cpp
	$(CC) $(CFLAGS) $(SRC_FILES) main.cpp -o $(NAME)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
