
INC = -I../../includes -I../
FLAGS = -Wall -Wextra -Werror --std=c++98
NAME = ft_map
all:
	clang++ $(FLAGS) $(INC) -o $(NAME) test_map.cpp
	./$(NAME)

valgr:
	valgrind ./$(NAME)