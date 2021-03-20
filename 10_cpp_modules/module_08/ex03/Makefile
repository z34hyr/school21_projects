
CC = clang++
FLAGS = -Wall -Wextra -Werror --std=c++98
NAME = main
LEAKCHECKER = valgrind
CPPFILES = main.cpp \
			Mindopen.cpp \
			./commands/Commands.cpp \
			./commands/NextPositionComm.cpp \
			./commands/PrevPositionComm.cpp \
			./commands/IncremComm.cpp \
			./commands/DecremComm.cpp \
			./commands/PrintSymbComm.cpp \
			./commands/PutSymbComm.cpp \
			./commands/WhileStartComm.cpp \
			./commands/WhileEndComm.cpp
			
EXAMPLES_DIR = ./examples/

all:
	$(CC) -o $(NAME) $(CPPFILES)
	./$(NAME) $(EXAMPLES_DIR)/simple.mindopener "hello Evaluator!"

valgr:
	$(CC) -o $(NAME) $(CPPFILES)
	$(LEAKCHECKER) ./$(NAME) $(EXAMPLES_DIR)/simple.mindopener