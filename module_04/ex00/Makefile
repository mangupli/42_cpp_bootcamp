NAME = ex00

COMPILER = clang++
FLAGS = -Wall -Werror -Wextra

FCLEAN		= @echo "\033[38;5;245mExecutable removed"
CLEAN		= @echo "\033[38;5;229mObject files removed"
DONE		= @echo "\033[38;5;200mCompiled!"

SRCS = main.cpp Animal.class.cpp Dog.class.cpp Cat.class.cpp

HEADERS = Animal.class.hpp Dog.class.hpp Cat.class.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(OBJS) -o $@
	$(DONE)

%.o: %.cpp $(HEADERS)
	$(COMPILER) $(FLAGS) -c $<

clean:
	@rm -rf $(OBJS)
	$(CLEAN)

fclean: clean
	@rm -rf $(NAME)
	$(FCLEAN)

re: fclean all

.PHONY: all re clean fclean
