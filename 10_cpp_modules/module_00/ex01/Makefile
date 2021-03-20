#phonebook makefile
CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = pooPhoneBook
SRCS =	main.cpp \
		Phonebook.class.cpp
OBJS = $(SRCS:.cpp=.o)

all:
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)
	@echo $(NAME) app created

fclean:
	@rm $(NAME)
	@echo $(NAME) app delete
