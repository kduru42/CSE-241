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
        Tetris() {};
        Tetris(int height, int width); //constructor
        Tetris(const Tetris &other);
        ~Tetris();
        inline int                      get_height() const {return (b_height);};
        inline int                      get_width() const {return (b_width);};
        inline int                      get_tetros_size() const {return (tetros_size);};
        static Pieces                   random_piece();
        void                            operator+= (const Tetromino &tetro);
        Tetris&                         operator= (const Tetris &other);
        void                            add_tetromino(const Tetromino &tetro);
        void                            draw_board() const;
        void                            animate_drop(Tetromino &tetro);
        void                            set_board();
    private:
        char **board;
        int tetros_size = 0;
        int b_height; //board height
        int b_width; //board width
};


#endif