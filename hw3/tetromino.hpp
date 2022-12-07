#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <iostream>
#include <string>
using namespace std;

/* Declaring enum class as a char enum to take input a char as a user*/
enum class Pieces : char
{
    I = 'I',
    O = 'O',
    T = 'T',
    J = 'J',
    L = 'L',
    S = 'S',
    Z = 'Z',
};

class Tetromino
{
    public:
        Tetromino () {};
        Tetromino(Pieces piece); //constructor
        Tetromino(const Tetromino &other);
        ~Tetromino();
        inline int              get_tetro_x_size() const {return (tetro_x_size);};
        inline int              get_tetro_y_size() const {return (tetro_y_size);};
        char**                  get_shape() const {return (tetros_shape);};
        static Pieces           get_piece(char a);
        Pieces                  get_which_p() const {return (which_p);};
        static void             swap_o(Tetromino **tetros);
        Tetromino&              operator=(const Tetromino &other);
        void                    rotate(const string rotation);
        void                    transpose(void);
        void                    mirror_y(void);
        void                    print() const;
        void                    set_shape();
    
    private:
        char **tetros_shape;
        int tetro_x_size;
        int tetro_y_size;
        Pieces which_p;
        char shape;
        
};


#endif