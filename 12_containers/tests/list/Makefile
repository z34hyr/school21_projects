INC = -I../../includes -I../
FLAGS = -Wall -Wextra -Werror --std=c++98
NAME = ft_list
all:
	clang++ $(FLAGS) $(INC) -o $(NAME) test_list.cpp
	#clang++ --std=c++98 $(INC) -o $(NAME) test_list.cpp
	./$(NAME)

valgr:
	valgrind ./$(NAME)