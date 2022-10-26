NAME = homework1
CC = g++
FLAGS = -std=c++11
RM = rm -rf

MAIN = main.o

SOURCE = tetromino.cpp

OBJECT = $(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) $(MAIN) -o $(NAME)

run: $(NAME)
	./homework1

clean:
	$(RM) ./*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re