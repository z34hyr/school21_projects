#main.cpp makefile
CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = main
SRCS =	main.cpp \
		FragTrap.cpp

all:
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)
	@echo $(NAME) app created
	./$(NAME)

fclean:
	@rm $(NAME)
	@echo $(NAME) app delete
