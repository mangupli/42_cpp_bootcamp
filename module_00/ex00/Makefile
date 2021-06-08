NAME = megaphone

COMPILER = clang++
FLAGS = -Wall -Werror -Wextra

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all:
	$(COMPILER) $(FLAGS) -c $(SRCS)
	$(COMPILER) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean