NAME1 = hw2driver1
NAME2 = hw2driver2
CC = g++
FLAGS = -std=c++11
RM = rm -rf

MAIN1 = driver1.o

MAIN2 = driver2.o

SOURCE = tetromino.cpp tetris.cpp

OBJECT = $(SOURCE:%.cpp=%.o)

all: fclean $(NAME2) $(NAME1)

$(NAME1): $(MAIN1) $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) $(MAIN1) -o $(NAME1)
	./$(NAME1)

$(NAME2): $(MAIN2) $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) $(MAIN2) -o $(NAME2)
	./$(NAME2)

clean:
	$(RM) ./*.o

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re 