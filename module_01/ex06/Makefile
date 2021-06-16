NAME = weapon
COMPILER = clang++
FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp HumanA.class.cpp HumanB.class.cpp Weapon.class.cpp

HEADERS = HumanA.class.hpp HumanB.class.hpp Weapon.class.hpp

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