NAME = Bureaucrat
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I../ex00

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re