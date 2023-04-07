CXX := c++

CFLAGS := -Wall -Wextra -Werror

PROJECT := ex02

SRCS :=	main.cpp	\
		Fixed.cpp

OBJS := $(addprefix .objs/, $(SRCS:.cpp=.o))

OBJS_DIRS := $(sort $(dir $(OBJS)))

NAME := $(PROJECT)

all: $(NAME)

$(NAME): Makefile $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(OBJS): | $(OBJS_DIRS)

$(OBJS_DIRS):
	mkdir -p $@

.objs/%.o: srcs/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	$(RM) $(NAME)

ffclean:
	rm -rf $(OBJS_DIRS)
	$(RM) $(NAME)

re: fclean all

norme:
	@norminette

.PHONY: all clean fclean ffclean re norme