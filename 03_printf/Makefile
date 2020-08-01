CCP = gcc
CFLAGS = -Wall -Wextra -Werror
TGTCFLAGS = -c
LIST_FUNC = conv_handler.c \
			ft_atoi.c \
			ft_conv_flag.c \
			ft_conv_line.c \
			ft_conv_spec_func.c \
			ft_conv_struc.c \
			ft_free_func.c \
			ft_itoa.c \
			ft_memset.c \
			ft_print_flags.c \
			ft_spec_iduxp.c \
			ft_spec_sc_perc.c \
			ft_uitoa.c \
			ft_printf.c \
			ft_n_flag_bonus.c

SOURCE_DIR = sources/

INCLUDES_DIR = includes/

CFILES = $(addprefix $(SOURCE_DIR), $(LIST_FUNC))

OFILES = $(patsubst %.c, %.o, $(CFILES))

NAME = libftprintf.a

.PHONY: all
all:	$(NAME)

# this sequence looks that .o files exist and .h file is up to date, \
so if not - it relinks library with updated files. 
$(NAME): $(OFILES) $(INCLUDES_DIR)ft_printf.h
	@echo "$(OFILES)"
	@ar rcs $(NAME) $(OFILES)
	@echo "$(NAME) successfully created!"

# this rule looks that .c files if up to date\exist. \
if not - it will compile needed .c files \
here $< is an automatic variable - the name of the first prerequisite \
https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
%.o: %.c
	$(CCP) $(CFLAGS) $(TGTCFLAGS) $< -o $@ -I$(INCLUDES_DIR)
.PHONY: clean
clean:
	@/bin/rm -f $(SOURCE_DIR)*.o

.PHONY: fclean
fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: bonus
bonus: all
	@echo "$(NAME) with bonus part successfully created!"

# so - rule to make shared library
so: 
	@gcc -Wall -Wextra -Werror -fPIC -c *.c 
	@gcc -shared -o libft.so *.o

.PHONY: re
re: fclean all

.PHONY: re_bonus
re_bonus: fclean bonus
