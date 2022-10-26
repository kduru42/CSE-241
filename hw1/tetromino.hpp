#ifndef TETROMINO_HPP
#define TETROMINE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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
        static void    fit_tetros(vector <Tetromino> &tetros);
        static Pieces  get_piece(char a);
        static void    print_best_fit(vector <Tetromino> &tetros);
        static void    swap_o(vector <Tetromino> &tetros);
        void           rotate(string rotation);
        void           transpose(void);
        void           mirror_y(void);
        void           print();
        bool           canFit(Tetromino &other, string o_position);
        void           set_shape();
    
    private:
        vector <vector<char>> tetros_shape;
        Pieces which_p;
        
};


#endif