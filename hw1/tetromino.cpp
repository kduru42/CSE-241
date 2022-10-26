#include "tetromino.hpp"

Tetromino::Tetromino(Pieces piece)
{
    which_p = piece;
}

/*Function to set the shape of tetromino according to enum info that taken from user.*/
void Tetromino::set_shape()
{
    if (which_p == Pieces::I)
    {
        tetros_shape.resize(1);
        for (int i = 0; i < 4; i++)
            tetros_shape[0].push_back('I');
    }
    else if (which_p == Pieces::O)
    {
        tetros_shape.resize(2);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tetros_shape[i].push_back('O');
    }
    else if (which_p == Pieces::T)
    {
        tetros_shape.resize(2);
        for (int i = 0; i < 3; i++)
            tetros_shape[0].push_back('T');
        tetros_shape[1].push_back(' ');
        tetros_shape[1].push_back('T');
        tetros_shape[1].push_back(' ');
    }
    else if (which_p == Pieces::J)
    {
        tetros_shape.resize(3);
        tetros_shape[0].push_back(' ');
        tetros_shape[0].push_back('J');
        tetros_shape[1].push_back(' ');
        tetros_shape[1].push_back('J');
        tetros_shape[2].push_back('J');
        tetros_shape[2].push_back('J');
    }
    else if (which_p == Pieces::L)
    {
        tetros_shape.resize(3);
        tetros_shape[0].push_back('L');
        tetros_shape[0].push_back(' ');
        tetros_shape[1].push_back('L');
        tetros_shape[1].push_back(' ');
        tetros_shape[2].push_back('L');
        tetros_shape[2].push_back('L');  
    }
    else if (which_p == Pieces::S)
    {
        tetros_shape.resize(2);
        tetros_shape[0].push_back(' ');
        tetros_shape[0].push_back('S');
        tetros_shape[0].push_back('S');
        tetros_shape[1].push_back('S');
        tetros_shape[1].push_back('S');
        tetros_shape[1].push_back(' '); 
    }
    else if (which_p == Pieces::Z)
    {
        tetros_shape.resize(2);
        tetros_shape[0].push_back('Z');
        tetros_shape[0].push_back('Z');
        tetros_shape[0].push_back(' ');
        tetros_shape[1].push_back(' ');
        tetros_shape[1].push_back('Z');
        tetros_shape[1].push_back('Z'); 
    }
}

/* Function to print tetrominos*/
void Tetromino::print()
{
    for (vector<char> a : tetros_shape)
    {
        for (char b: a)
            cout << b;
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
    vector <vector<char>> temp;
    temp.resize(this->tetros_shape[0].size());
    for (int i = 0; i < this->tetros_shape.size(); i++)
        for (int j = 0; j < this->tetros_shape[0].size(); j++)
            temp[j].push_back(this->tetros_shape[i][j]);
    this->tetros_shape = temp;
}

/*Then mirroring transposed vector according to y axis*/
void Tetromino::mirror_y(void)
{
    char    temp;
    int     k;     
    for (int i = 0; i < this->tetros_shape.size(); i++)
    {
        k = this->tetros_shape[0].size() - 1;
        for (int j = 0; j < this->tetros_shape[0].size() / 2; j++)
        {
            temp = this->tetros_shape[i][j];
            this->tetros_shape[i][j] = this->tetros_shape[i][k];
            this->tetros_shape[i][k] = temp;
            k--;
        }
    }
}

/*Rotating funciton*/
void Tetromino::rotate(string rotate)
{
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


bool Tetromino::canFit(Tetromino &other, string o_position)
{
    int act_y = this->tetros_shape.size() - 1; //actual tetro's y axis
    int act_x = this->tetros_shape[0].size() - 1; //actual tetro's x axis
    int oth_y = other.tetros_shape.size() - 1; // other tetro's y axis
    int oth_x = other.tetros_shape[0].size() - 1; // other tetro's x axis
    if (o_position == "right")
    {
        if (this->tetros_shape[act_y][act_x] != ' ' && other.tetros_shape[oth_y][0] != ' ')
            return (true);
        if (this->tetros_shape[act_y][act_x] == ' ' && other.tetros_shape[oth_y][0] != ' ')
        {
            if (oth_y + 1 == 1)
                return (true);
            if (other.tetros_shape[oth_y - 1][0] != ' ')
                return (false);
        }
        if (this->tetros_shape[act_y][act_x] != ' ' && other.tetros_shape[oth_y][0] == ' ')
        {
            if (act_y + 1 == 1)
                return (true);
            if (this->tetros_shape[act_y - 1][act_x] != ' ')
                return (false);
        }
        if (this->tetros_shape[act_y][act_x] == ' ' && other.tetros_shape[oth_y][0] == ' ')
            return (false);
        return (true);
    }
    return (true);
}


void Tetromino::swap_o(vector <Tetromino> &tetros)
{
    int count = 0;
    for (int i = 0; i < tetros.size(); i++)
        if (tetros[i].which_p == Pieces::O)
        {
            swap(tetros[count], tetros[i]);
            count++;
        }
}


void Tetromino::fit_tetros(vector <Tetromino> &tetros)
{
    vector <vector<char>> fitted;
    swap_o(tetros);
    int total_col = 0;
    int total_temp = 0;
    fitted.resize(4);
    for (int i = 0; i < 4; i++)
        fitted[i].resize(50);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 50; j++)
            fitted[i].push_back(' ');
    for (int i = 0; i < tetros[0].tetros_shape.size(); i++)
    {
        total_col = total_temp;
        for (int j = 0; j < tetros[0].tetros_shape[0].size(); j++)
        {
            fitted[3 - i][total_col] = tetros[0].tetros_shape[tetros[0].tetros_shape.size() - i - 1][j];
            total_col++;
        }
    }
    total_temp = total_col;
    for (int i = 0; i < tetros.size() - 1; i++)
    {
        if (tetros[i].canFit(tetros[i + 1], "right"))
        {
            for (int k = 0; k < tetros[i + 1].tetros_shape.size(); k++)
            {
                total_col = total_temp;
                for (int j = 0; j < tetros[i + 1].tetros_shape[0].size(); j++)
                {
                    fitted[3 - k][total_col] = tetros[i + 1].tetros_shape[tetros[i + 1].tetros_shape.size() - k - 1][j];
                    total_col++;
                }
            }
            total_temp = total_col;
        }
        else
        {
            tetros[i + 1].rotate("right");
            i--;
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < total_col; j++)
            if (fitted[i][j] != 'I' && fitted[i][j] != 'O' && fitted[i][j] != 'L'
                 && fitted[i][j] != 'S' && fitted[i][j] != 'Z' && fitted[i][j] != 'J' && fitted[i][j] != 'T')
                    fitted[i][j] = ' ';
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < total_col; j++)
        {
            if ((i == 2 && j > 0 && fitted[i][j] == ' ' && fitted[i][j - 1] != ' ' && fitted[i + 1][j] != ' ' && fitted[i + 1][j - 1] == ' ')
                    || (i == 2 && j < total_col - 1 && fitted[i][j] == ' ' && fitted[i][j + 1] != ' ' && fitted[i + 1][j] != ' ' && fitted[i + 1][j + 1] == ' '))
                    {
                        for (int x = j; j < total_col; j++)
                        {
                            if (fitted[1][j] == ' ')
                            {
                                fitted[1][j] = 'X';
                                break;
                            }
                        }
                        for (int x = j; j < total_col; j++)
                        {
                            if (fitted[0][j] == ' ')
                            {
                                fitted[0][j] = 'X';
                                break;
                            }
                        }
                    }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < total_col; j++)
        {
            if ((i == 3 && j > 0 && fitted[i][j] == ' ' && fitted[i][j - 1] != ' ' && fitted[i - 1][j] != ' ' && fitted[i - 1][j - 1] == ' ')
                    || (i == 3 && j < total_col - 1 && fitted[i][j] == ' ' && fitted[i][j + 1] != ' ' && fitted[i - 1][j] != ' ' && fitted[i - 1][j + 1] == ' ')
                    || (i == 2 && j > 0 && fitted[i][j] == ' ' && fitted[i][j - 1] != ' ' && fitted[i + 1][j] != ' ' && fitted[i + 1][j - 1] == ' ')
                    || (i == 2 && j < total_col - 1 && fitted[i][j] == ' ' && fitted[i][j + 1] != ' ' && fitted[i + 1][j] != ' ' && fitted[i + 1][j + 1] == ' ')
                    || fitted[i][j] == 'X')
            {

            }
            else
                cout << fitted[i][j];
        }
        cout << endl;
    }
}