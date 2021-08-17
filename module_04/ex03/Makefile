# Compilation #

NAME = ex03
COMPILER = clang++
FLAGS = -W -Wall -Wextra

# Output #

FCLEAN		= @echo "\033[38;5;245mExecutable removed"
CLEAN		= @echo "\033[38;5;229mObject files removed"
DONE		= @echo "\033[38;5;200mCompiled!"

# Object files #

OBJS_DIR = ./objs/
OBJS_FILES = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

# Source files #

SRCS = main.cpp \
			AMateria.class.cpp \
						Cure.class.cpp \
							Ice.class.cpp \
							 MateriaSource.class.cpp \
							 	Character.class.cpp \


HEADERS = AMateria.class.hpp  MateriaSource.class.hpp \
			Cure.class.hpp Ice.class.hpp IMateriaSource.class.hpp \
				ICharacter.class.hpp Character.class.hpp

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
