AC = nasm
CC = gcc
NAME = libasm.a
SOURCES =	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s

OBJ = $(SOURCES:.s=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.s
	$(AC) -f elf64 $<

.PHONY: main
main: all
	$(CC) -no-pie -o main main.c -L. -lasm
	@echo "so result is:\n\n"
	./main

.PHONY: clean
clean:
	/bin/rm -f *.o

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
