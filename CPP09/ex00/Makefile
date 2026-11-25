NAME = btc
SRC = main.cpp BitcoinExchange.cpp
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
	rm -f input.txt

re: fclean all

.PHONY: all clean fclean re

test_input:
	@echo "date | value" > input.txt
	@echo "2011-01-03 | 3" >> input.txt
	@echo "2011-01-03 | 2" >> input.txt
	@echo "2011-01-03 | 1" >> input.txt
	@echo "2011-01-03 | 1.2" >> input.txt
	@echo "2011-01-09 | 1" >> input.txt
	@echo "2012-01-11 | -1" >> input.txt
	@echo "2001-42-42" >> input.txt
	@echo "2012-01-11 | 1" >> input.txt
	@echo "2012-01-11 | 2147483648" >> input.txt
	@echo "2030-01-33 | 1" >> input.txt
	@echo "2008-11-30 | 1" >> input.txt
	@echo "2020-02-29 | 1" >> input.txt
	@echo "2020-02-30 | 1" >> input.txt
	@echo "2019-02-29 | 1" >> input.txt
	@echo "2019-02-28 | 1" >> input.txt
	@echo "202a-05-02 | 1" >> input.txt
	@echo "2024-00-02 | 1" >> input.txt

test: test_input
	./btc input.txt
