
INC = -I../../includes -I../
FLAGS = -Wall -Wextra -Werror --std=c++98
NAME = ft_queue

all:
	clang++ $(FLAGS) $(INC) -o $(NAME) test_queue.cpp
	./$(NAME)

valgr:
	valgrind ./$(NAME)