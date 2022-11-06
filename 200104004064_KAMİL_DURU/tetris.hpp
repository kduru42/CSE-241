#ifndef TETRIS_HPP
# define TETRIS_HPP

# include "tetromino.hpp"
# include <cstdlib> //for rand() function
# include <ctime>
# include <thread> // to sleep between draw_board's
# include <chrono>

class Tetris
{
    public:
        Tetris(int height, int width); //constructor
        inline vector <vector<char>>    &get_board() {return (board);}; //getter of board
        inline vector <Tetromino>       &get_tetros() {return (tetros);}; //getter of tetro vector
        inline int                      get_height() {return (b_height);};
        inline int                      get_width() {return (b_width);};
        static Pieces                   random_piece();
        void                            add_tetromino(Tetromino &tetro);
        void                            fit_tetro(Tetromino &tetro);
        void                            draw_board() const;
        void                            animate_drop(Tetromino &tetro);
        void                            set_board();
        void                            slip_into_tetro(Tetromino &tetro);
    private:
        int b_height; //board height
        int b_width; //board width
        vector <vector<char>> board;
        vector <Tetromino> tetros; //vector of tetrominos
        int add_col = 0; // variable to save index after last tetromino
        int add_col2 = 0; // variable to save index after last tetromino
};

#endif