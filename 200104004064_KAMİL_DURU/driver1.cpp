#include "tetris.hpp"

int main()
{
    Tetromino tetro(Pieces::Z);
    tetro.set_shape();
    Tetromino other(Pieces::Z);
    other.set_shape();
    Tetris game(10, 50);
    vector<Tetromino> tetros;
    tetros.push_back(tetro);
    tetros.push_back(other);
    cout << "Testing print funciton of Tetromino class" << endl;
    tetro.print();
    cout << "Testing transpose funciton of Tetromino class" << endl;
    tetro.transpose();
    tetro.print();
    cout << "Testing mirror_y function of Tetromino class" << endl;
    tetro.mirror_y();
    tetro.print();
    cout << "Testing rotate funciton of Tetromino class" << endl;
    tetro.rotate("right");
    tetro.print();
    cout << "Testing fit_tetros function of Tetromino class" << endl;
    Tetromino::fit_tetros(tetros);
    game.get_tetros() = tetros;

    cout << "Testing add_tetromino function of Tetris class" << endl;
    game.add_tetromino(tetro);
    game.draw_board();
    cout << endl << "Testing fit_tetro function of Tetris class" << endl;
    game.fit_tetro(tetro);
    game.draw_board();
    cout << "Testing animate_drop funciton of Tetris class" << endl;
    game.animate_drop(tetro);
    return (0);
}