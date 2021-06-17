NAME = replace
COMPILER = clang++
#FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(OBJS) -o $@

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)
	rm -rf *.replace

re: fclean all

.PHONY: all re clean fclean