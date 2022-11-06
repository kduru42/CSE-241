#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <iostream>
#include <string>
#include <vector>
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
        Tetromino(Pieces piece); //constructor
        vector<vector<char>>    get_shape() {return (tetros_shape);};
        static void             fit_tetros(vector <Tetromino> &tetros);
        static Pieces           get_piece(char a);
        Pieces                  get_which_p() {return (which_p);};
        static void             swap_o(vector <Tetromino> &tetros);
        void                    rotate(const string rotation);
        void                    transpose(void);
        void                    mirror_y(void);
        void                    print() const;
        bool                    canFit(const Tetromino &other, string o_position) const;
        void                    set_shape();
    
    private:
        vector <vector<char>> tetros_shape;
        Pieces which_p;
        char shape;
        
};


#endif