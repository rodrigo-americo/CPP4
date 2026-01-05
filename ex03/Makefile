NAME    = main
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC     = main.cpp MateriaSource.cpp Character.cpp Ice.cpp Cure.cpp AMateria.cpp
OBJ     = $(SRC:.cpp=.o)
HEADER  = IMateriaSource.hpp MateriaSource.hpp ICharacter.hpp Character.hpp Ice.hpp Cure.hpp AMateria.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re