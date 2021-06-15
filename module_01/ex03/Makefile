NAME = zombie

COMPILER = clang++
FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp Zombie.class.cpp ZombieHorde.class.cpp

HEADERS = Zombie.class.hpp ZombieHorde.class.hpp

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