#megaphone.cpp makefile
CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all:
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)
	@echo $(NAME) app created

fclean:
	@rm $(NAME)
	@echo $(NAME) app delete
