NAME = ex01

COMPILER = clang++
FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp ClapTrap.class.cpp ScavTrap.class.cpp

HEADERS =  ClapTrap.class.hpp ScavTrap.class.hpp

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