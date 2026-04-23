NAME = RPN
SRC = main.cpp RPN.cpp
OBJS = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

test:
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./RPN "7 7 * 7 -"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	./RPN  "(1 + 1)"