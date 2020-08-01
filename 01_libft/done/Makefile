CCP = gcc
CFLAGS = -Wall -Wextra -Werror
TGTCFLAGS = -c
CFILES = 	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BCFILES = 	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OFILES = $(CFILES:.c=.o)
BOFILES = $(BCFILES:.c=.o)

NAME = libft.a

ifdef ADD_BONUS
LIB_OFILES = $(OFILES) $(BOFILES)
else
LIB_OFILES = $(OFILES)
endif


.PHONY: all
all:	$(NAME)

$(NAME): $(LIB_OFILES) libft.h
	@echo "$(LIB_OFILES)"
	@ar rcs $(NAME) $(LIB_OFILES)
	@echo "$(NAME) successfully created!"

%.o: %.c
	$(CCP) $(CFLAGS) $(TGTCFLAGS) $<

.PHONY: clean
clean:
	@/bin/rm -f *.o

.PHONY: fclean
fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: bonus
bonus: 
	$(MAKE) ADD_BONUS=1 all
	@echo "$(NAME) with bonus part successfully created!"

.PHONY: re
re: fclean all

.PHONY: re_bonus
re_bonus: fclean bonus
