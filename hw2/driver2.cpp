#include "tetris.hpp"

int main()
{
    int height, width;
    char option;
    char piece_type;
    cout << "Welcome to the Tetris Game!!" << endl;
    cout << "Please enter sizes of the board" << endl;
    while (1)
    {
        cout << "Height: ";
        cin >> height;
        cout << "Width: ";
        cin >> width;
        if ((height > 0 && height < 100) && (width > 0 && width < 100))
            break;
        else
        {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    Tetris game(height, width);
    game.draw_board();
    do 
    {
        // cout << "\033[s";
        cout << "Please enter the tetromino shape: ";
        cin >> piece_type;
        if (piece_type == 'I' || piece_type == 'O' || piece_type == 'T' || piece_type == 'J' 
            || piece_type == 'L' || piece_type == 'S' || piece_type == 'Z')
        {
            game.get_tetros().push_back(Tetromino::get_piece(piece_type));
            game.get_tetros()[game.get_tetros().size() - 1].set_shape();
            game.add_tetromino(game.get_tetros()[game.get_tetros().size() - 1]);
            game.animate_drop(game.get_tetros()[game.get_tetros().size() - 1]);
        }
        else if (piece_type == 'R')
        {
            game.get_tetros().push_back(Tetris::random_piece());
            game.get_tetros()[game.get_tetros().size() - 1].set_shape();
            game.add_tetromino(game.get_tetros()[game.get_tetros().size() - 1]);
            game.animate_drop(game.get_tetros()[game.get_tetros().size() - 1]);
        }
        else if (piece_type == 'Q')
            cout << "GAME OVER!" << endl;
        else
        {
           // cout << "Invalid piece type. Please try again." << endl;
            cin.clear();
            cin.ignore();
        }
    } while (piece_type != 'Q');
}