# Compilation #

NAME = convert
COMPILER = clang++
FLAGS = -W -Wall -Wextra -Wconversion -std=c++98

# Output #

FCLEAN		= @echo "\033[38;5;245mExecutable removed"
CLEAN		= @echo "\033[38;5;229mObject files removed"
DONE		= @echo "\033[38;5;200mCompiled! Executable name: $(NAME)"

# Object files #

OBJS_DIR = ./objs/
OBJS_FILES = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

# Source files #

SRCS = main.cpp Conversion.class.cpp

HEADERS = Conversion.class.hpp

# Rules #

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(OBJS) -o $@
	$(DONE)

$(OBJS_DIR)%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	$(CLEAN)

fclean: clean
	rm -rf $(NAME)
	$(FCLEAN)

re: fclean all

.PHONY: all re clean fclean