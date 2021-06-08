NAME = phonebook

COMPILER = clang++
FLAGS = -Wall -Werror -Wextra

HEADERS = Contact.class.hpp PhoneBook.class.hpp
SRCS = main.cpp \
		Contact.class.cpp PhoneBook.class.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(HEADERS)
	$(COMPILER) $(FLAGS) -c $(SRCS)
	$(COMPILER) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean