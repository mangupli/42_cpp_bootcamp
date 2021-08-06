NAME = ex03

COMPILER = clang++
FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp Fixed.class.cpp Point.class.cpp bsp.cpp

HEADERS = Fixed.class.hpp Point.class.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(COMPILER) $(FLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean