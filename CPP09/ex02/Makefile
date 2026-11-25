NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp sortVector.cpp sortDeque.cpp
OBJS = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

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

test: all
	./$(NAME) `jot -r 12 1 100 | tr '\n' ' '`
	./$(NAME) `jot -r 100 1 100 | tr '\n' ' '`