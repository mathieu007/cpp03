NAME = DiamondTrap
SRC = 	main.cpp	\
		ClapTrap.cpp	\
		ScavTrap.cpp	\
		FragTrap.cpp	\
		DiamondTrap.cpp		\

OBJ = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.hpp)  # Include header files as dependencies
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Wshadow -Wno-shadow -I.

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE)$(GRAY)- Compiling $(NAME)... $(RESET)\n"
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)- Executable ready.\n$(RESET)"

%.o: %.cpp $(DEPS)  # Include header files as dependencies for .cpp files, important or might break compilation
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@printf "$(YELLOW)- Objects removed.$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	@printf "$(YELLOW)- Executable removed.$(RESET)\n"

re: fclean $(NAME)

.PHONY: all clean fclean re
