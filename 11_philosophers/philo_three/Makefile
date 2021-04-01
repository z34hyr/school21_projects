# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 01:37:08 by qmalcom           #+#    #+#              #
#    Updated: 2021/03/29 23:45:54 by qmalcom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS =	main.c \
		terms.c \
		ft_atol.c \
		ft_llitoa.c \
		ft_strlen.c \
		func_philo/philo_init.c \
		func_philo/philo.c \
		func_philo/philo_eat.c \
		func_philo/messages.c \
		table.c \
		ft_putstr_fd.c \
		ft_strjoin.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = philo_three

.PHONY: all
all: $(NAME)
	@echo "done! (all)"

$(NAME): $(OBJS)
	gcc ${CFLAGS} -pthread -o ${NAME} ${OBJS}

$(OBJS): philo.h

.PHONY: clean
clean:
	rm -f $(OBJS)
	@echo "done! (clean)"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo "done! (fclean)"

.PHONY: re
re: fclean all
	@echo "done! (re)"
