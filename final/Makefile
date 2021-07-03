
CC = clang++
RM = rm -rf
FLAGS = --std=c++98 -Wall -Wextra -Werror -I$(INCLUDES) -I$(PARSE_INCLUDES)
INCLUDES =	include

PARSE_INCLUDES =	config_parser

NAME = server
SRC =	srcs/main.cpp \
		srcs/Client.cpp \
		srcs/Response.cpp \
		srcs/Request.cpp \
		srcs/Server.cpp \
		srcs/utils.cpp \
		config_parser/parse_config.cpp \
		config_parser/get_next_line.cpp \
		config_parser/Location.cpp \
		config_parser/ServerConf.cpp \
		config_parser/toReturn.cpp
OBJ = $(SRC:.cpp=.o)
INC_OBJ = include/Client.hpp \
		include/Response.hpp \
		include/Request.hpp \
		include/Server.hpp \
		include/webserv.hpp \
		config_parser/parse_config.hpp \
		config_parser/get_next_line.hpp \
		config_parser/Location.hpp \
		config_parser/ServerConf.hpp \
		config_parser/toReturn.hpp

all: $(NAME)

$(NAME): $(OBJ) $(INC_OBJ)
	@$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

retest: re test
test: all
	./$(NAME) test/test.config
log: all
	./$(NAME) 2>log
nginx-new:
	docker run --name nginx-for-test -p 4242:80 -d nginx
nginx-run:
	docker start nginx-for-test
nginx-stop:
	docker container stop nginx-for-test

.PHONY: all clean fclean re
