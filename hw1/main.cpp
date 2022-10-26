#include "tetromino.hpp"

int main()
{
	char    piece_type;
	int     i = 0;
	int 	number_of_tetrominos;
	vector <Tetromino> tetros;
	cout << "Welcome to the Tetris Game!!" << endl;
	cout << "How many tetrominos?" << endl;
	cin >> number_of_tetrominos;
	cout << "What are the types?" << endl;
	while (i < number_of_tetrominos)
	{
		cin >> piece_type;
		if (piece_type == 'I' || piece_type == 'O' || piece_type == 'T' || piece_type == 'J' 
			|| piece_type == 'L' || piece_type == 'S' || piece_type == 'Z')
		{
			tetros.push_back((Tetromino::get_piece(piece_type)));
			tetros[i].set_shape();
		}
		else
		{
			cout << "Invalid piece type. Please try again." << endl;
			i--;
		}
		i++;
	}
	cout << "Your tetrominos" << endl;
	for (int j = 0; j < number_of_tetrominos; j++)
		tetros[j].print();
	cout << "Horizotally best-fit tetrominos\n";
	Tetromino::fit_tetros(tetros);
}
