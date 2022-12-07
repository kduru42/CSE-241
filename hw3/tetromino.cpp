#include "tetromino.hpp"

Tetromino::Tetromino(Pieces piece)
{
    which_p = piece;
    if (piece == Pieces::I)
        tetro_x_size = 1; tetro_y_size = 4;
    if (piece == Pieces::O)
        tetro_x_size = 2, tetro_y_size = 2;
    if (piece == Pieces::J)
        tetro_x_size = 2, tetro_y_size = 3;
    if (piece == Pieces::L)
        tetro_x_size = 2, tetro_y_size = 3;
    if (piece == Pieces::S)
        tetro_x_size = 3, tetro_y_size = 2;
    if (piece == Pieces::Z)
        tetro_x_size = 3, tetro_y_size = 2;
    if (piece == Pieces::T)
        tetro_x_size = 3, tetro_y_size = 2;
    set_shape();
}

Tetromino::Tetromino(const Tetromino &other)
{
    tetros_shape = new char * [other.tetro_y_size];
    for (int i = 0; i < other.tetro_y_size; i++)
        tetros_shape[i] = new char [other.tetro_x_size];
    for (int i = 0; i < other.tetro_y_size; i++)
        for (int j = 0; j < other.tetro_x_size; j++)
            tetros_shape[i][j] = other.get_shape()[i][j];
    which_p = other.which_p;
    shape = other.shape;
}

Tetromino::~Tetromino()
{
    int y_size = tetro_y_size;
    for (int i = 0; i < y_size; i++)
        delete [] tetros_shape[i];
    delete [] tetros_shape;
}

/*Function to set the shape of tetromino according to enum info that taken from user.*/
void Tetromino::set_shape()
{
    if (which_p == Pieces::I)
    {
        tetros_shape = new char * [4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 1; j++)
            {
                tetros_shape[i] = new char [1];
                tetros_shape[i][j] = 'I';
            }
        }
        shape = 'I';
    }
    else if (which_p == Pieces::O)
    {
        tetros_shape = new char * [2];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                tetros_shape[i] = new char [2];
                tetros_shape[i][j] = 'O';
            }
        }
        shape = 'O';
    }
    else if (which_p == Pieces::T)
    {
        tetros_shape = new char * [2];
        for (int i = 0; i < 2; i++)
            tetros_shape[i] = new char [3];
        for (int i = 0; i < 3; i++)
            tetros_shape[0][i] = 'T';
        tetros_shape[1][0] = '-';
        tetros_shape[1][1] = 'T';
        tetros_shape[1][2] = '-';
        shape = 'T';
    }
    else if (which_p == Pieces::J)
    {
        tetros_shape = new char * [3];
        for (int i = 0; i < 3; i++)
            tetros_shape[i] = new char [2];
        tetros_shape[0][0] = '-';
        tetros_shape[0][1] = 'J';
        tetros_shape[1][0] = '-';
        tetros_shape[1][1] = 'J';
        tetros_shape[2][0] = 'J';
        tetros_shape[2][1] = 'J';
        shape = 'J';
    }
    else if (which_p == Pieces::L)
    {
        tetros_shape = new char * [3];
        for (int i = 0; i < 3; i++)
            tetros_shape[i] = new char [2];
        tetros_shape[0][0] = 'L';
        tetros_shape[0][1] = '-';
        tetros_shape[1][0] = 'L';
        tetros_shape[1][1] = '-';
        tetros_shape[2][0] = 'L';
        tetros_shape[2][1] = 'L';
        shape = 'L';  
    }
    else if (which_p == Pieces::S)
    {
        tetros_shape = new char * [2];
        for (int i = 0; i < 2; i++)
            tetros_shape[i] = new char [3];
        tetros_shape[0][0] = '-';
        tetros_shape[0][1] = 'S';
        tetros_shape[0][2] = 'S';
        tetros_shape[1][0] = 'S';
        tetros_shape[1][1] = 'S';
        tetros_shape[1][2] = '-';
        shape = 'S'; 
    }
    else if (which_p == Pieces::Z)
    {
        tetros_shape = new char * [2];
        for (int i = 0; i < 2; i++)
            tetros_shape[i] = new char [3];
        tetros_shape[0][0] = 'Z';
        tetros_shape[0][1] = 'Z';
        tetros_shape[0][2] = '-';
        tetros_shape[1][0] = '-';
        tetros_shape[1][1] = 'Z';
        tetros_shape[1][2] = 'Z';
        shape = 'Z'; 
    }
}

/* Function to print tetrominos*/
void Tetromino::print() const
{
    for (int i = 0; i < tetro_y_size; i++)
    {
        for (int j = 0; j < tetro_x_size; j++)
            cout << tetros_shape[i][j];
        cout << endl;
    }
}

/* Function to get data to pass as argument to constructor according to input taken from user*/
Pieces Tetromino::get_piece(char a)
{
    if (a == 'I')
        return (Pieces::I);
    else if (a == 'O')
        return (Pieces::O);
    else if (a == 'T')
        return (Pieces::T);
    else if (a == 'J')
        return (Pieces::J);
    else if (a == 'L')
        return (Pieces::L);
    else if (a == 'S')
        return (Pieces::S);
    else
        return (Pieces::Z);
}


/*To rotate, it transposes the Tetrominos vector*/
void Tetromino::transpose(void)
{
    int temp1;
    char **temp;
    int x_size = tetro_x_size;
    int y_size = tetro_y_size;
    temp = new char * [x_size];
    for (int i = 0; i < x_size; i++)
        temp[i] = new char [y_size];
    for (int i = 0; i < y_size; i++)
        for (int j = 0; j < x_size; j++)
            temp[j][i] = tetros_shape[i][j];
    for (int i = 0; i < y_size; i++)
        delete [] tetros_shape[i];
    delete [] tetros_shape;
    this->tetros_shape = temp;
    temp1 = tetro_y_size;
    tetro_y_size = tetro_x_size;
    tetro_x_size = temp1;
}

/*Then mirroring transposed vector according to y axis*/
void Tetromino::mirror_y(void)
{
    char    temp;
    int     k;     
    for (int i = 0; i < this->tetro_y_size; i++)
    {
        k = this->tetro_x_size - 1;
        for (int j = 0; j < this->tetro_x_size / 2; j++)
        {
            temp = this->tetros_shape[i][j];
            this->tetros_shape[i][j] = this->tetros_shape[i][k];
            this->tetros_shape[i][k] = temp;
            k--;
        }
    }
}

/*Rotating funciton*/
void Tetromino::rotate(const string rotate)
{
    int temp;
    if (rotate == "right")
    {
        this->transpose();
        this->mirror_y();
    }
    else if (rotate == "left")
    {
        this->mirror_y();
        this->transpose();
    }
}


Tetromino& Tetromino::operator= (const Tetromino &other)
{
    if (shape == other.shape)
        return (*this);
    char **temp;
    int xo_size = other.tetro_x_size;
    int yo_size = other.tetro_y_size;
    int y_size = tetro_y_size;
    temp = new char * [yo_size];
    for (int i = 0; i < yo_size; i++)
        temp[i] = new char [xo_size];
    for (int i = 0; i < yo_size; i++)
        for (int j = 0; j < xo_size; j++)
            temp[i][j] = other.tetros_shape[i][j];
    for (int i = 0; i < y_size; i++)
        delete [] tetros_shape[i];
    delete [] tetros_shape;
    tetros_shape = temp;
    this->which_p = other.which_p;
    this->shape = other.shape;
    return (*this);
}

