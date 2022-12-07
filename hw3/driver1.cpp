#include "tetris.hpp"

int main()
{
    Tetromino tetro(Pieces::J);
    Tetromino tetro2(Pieces::T);
    tetro2 = tetro;
    tetro2.print();

    return 0;
}