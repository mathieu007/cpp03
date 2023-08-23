NAME = ClapTrap
SRC = 	main.cpp	\
		ClapTrap.cpp	\
		ScavTrap	\

OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I./

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

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@printf "$(YELLOW)- Objects removed.$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	@printf "$(YELLOW)- Executable removed.$(RESET)\n"

re: fclean $(NAME)

.PHONY: all clean fclean re
