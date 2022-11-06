#include "tetris.hpp"

//Constructor
Tetris::Tetris(int height, int width)
{
    b_height = height;
    b_width = width;
    set_board();
}

/* Function to set all indexes of board with '-' charachter before any apllies */
void Tetris::set_board()
{
    board.resize(b_height);
    for (int i = 0; i < b_height; i++)
        for (int j = 0; j < b_width; j++)
            board[i].push_back('-');
}

/* Function to add a tetromino to the middle-top of board */
void Tetris::add_tetromino(Tetromino &tetro)
{
    vector <vector<char>>   shape;
    int                     index;

    shape = tetro.get_shape();
    for (int i = 0; i < shape.size(); i++)
    {
        index = 0;
        for (int j = (b_width - shape[0].size()) / 2; j < (b_width + shape[0].size()) / 2; j++) //adding tetro to the middle
        {
            board[i][j] = shape[i][index]; 
            index++;
        }
    }
}

/* Function to draw board */
void Tetris::draw_board() const
{
    for (auto a : board)
    {
        for (auto b : a)
            cout << b;
        cout <<endl;
    }
}

/* Function to replace tetromino to the index after last tetromino and rotates it according to fitting situtation */
void Tetris::fit_tetro(Tetromino &tetro)
{
    int size1;
    int size2;
    int index1;
    int index2;
    int reps = 0; // If tetromino rotates four times, it puts tetromino right to the last tetro even they can't fit each other
    // Controlling if is there any non-fit situtaion between the first tetromino and left side of board. If there is, it rotates the tetromino 
    if (tetros.size() == 1 && (tetro.get_which_p() == Pieces::T || tetro.get_which_p() == Pieces::Z))
    {
        tetro.rotate("left");
        add_tetromino(tetro);
    }
    size1 = tetro.get_shape().size();
    size2 = tetro.get_shape()[0].size();
    index1 = tetros.size() - 2;
    while (1)
    {
        //If the tetro is the first, it fits directly to the left side of board
        if (tetros.size() == 1)
        {
            for (int j = 0; j < size1; j++)
                for (int k = 0; k < size2; k++)
                    swap(board[j][k], board[j][(b_width - size2) / 2 + k]);
            add_col += size2;
            break;
        }
        //If the total col_sizes of tetros arrives boards col size, game ends
        else if (add_col + tetro.get_shape()[0].size() > board[0].size())
        {
            cout << endl << "GAME OVER!!";
            exit(1);
        }
        //else, it controls fitting situtation between tetrominos and rotates right hand side tetro according to fitting situation
        else if (tetros[index1].canFit(tetro, "right") || reps == 4)
        {
            // Debugging middle tetro problem. Swap function overlaps without this if condition
            if (add_col >= (b_width - size2) / 2 && add_col <= (b_width + size2) / 2)
            {
                for (int j = 0; j < size1; j++)
                {
                    int index = size2 - 1;
                    for (int k = add_col + size2 - 1; k >= add_col; k--)
                    {
                        swap(board[j][k], board[j][(b_width - size2) / 2 + index]);
                        index--;
                    }
                }               
            }
            else
            {
                for (int j = 0; j < size1; j++)
                {
                    int index = 0;
                    for (int k = add_col; k < add_col + size2; k++)
                    {
                        swap(board[j][k], board[j][(b_width - size2) / 2 + index]);
                        index++;
                    }
                }
            }
            add_col += size2; // Adds the size of tetro statically so total size will be saved
            reps = 0;
            break;
        }
        else
        {
            // If tetromino can't fit, it rotates the tetromino and adds rotated form of it again.
            for (int i = 0; i < tetro.get_shape().size(); i++)
            {
                int idx = 0;
                for (int j = 0; j  < board[0].size(); j++)
                    if (board[i][j] == tetro.get_shape()[i][idx])
                    {
                        board[i][j] = '-';
                        idx++;
                    }
            }
            tetro.rotate("right");
            add_tetromino(tetro);
            size1 = tetro.get_shape().size();
            size2 = tetro.get_shape()[0].size();
            reps++;
        }
    }
}
/* Function to animate the drop of tetromino to the bottom */
void Tetris::animate_drop(Tetromino &tetro)
{
    draw_board();
    fit_tetro(tetro);
    this_thread::sleep_for(chrono::milliseconds(50)); //sleeps between every draw_board
    draw_board();
    this_thread::sleep_for(chrono::milliseconds(50));
    // It decrease index one by one and waits 50 ms
    for (int i = tetro.get_shape().size(); i < board.size(); i++)
    {
        for (int j = board.size(); j >= 1; j--)
        {
            for (int k = add_col2; k < add_col2 + tetro.get_shape()[0].size(); k++)
            {
                if (board[j - 1][k] != '-')
                    swap(board[j][k], board[j - 1][k]);
            }
        }
        draw_board();
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    add_col2 += tetro.get_shape()[0].size();
    /* Finally when it arrives to the bottom, it slips one left according to how much spaces it can slip */
    if (tetros.size() > 1)
    {
        slip_into_tetro(tetro);
        draw_board();
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}
/* Function to return a random piece type */
Pieces Tetris::random_piece()
{
    int random_p;
    srand(time(0));
    
    random_p = rand() % 7 + 1;
    if (random_p == 1)
        return (Pieces::I);
    else if (random_p == 2)
        return (Pieces::O);
    else if (random_p == 3)
        return (Pieces::T);
    else if (random_p == 4)
        return (Pieces::J);
    else if (random_p == 5)
        return (Pieces::L);
    else if (random_p == 6)
        return (Pieces::S);
    else
        return (Pieces::Z);
}
/* Function to fit tetros with slipping to the left*/
void Tetris::slip_into_tetro(Tetromino &tetro)
{
    /* if tetros can't fit it returns */
    if (!tetros[tetros.size() - 2].canFit(tetro, "right"))
        return ;
    int flag = 0; // When tetromino slips once, it controls if it can slip once again. If it can, flag becomes 1
    int size1 = tetro.get_shape().size() - 1;
    int size2 = tetro.get_shape()[0].size() - 1;
    int o_size1 = tetros[tetros.size() - 2].get_shape().size() - 1;
    int o_size2 = tetros[tetros.size() - 2].get_shape()[0].size() - 1;
    /* If both sides of tetrominos aren't empty, it means they can fit */
    if ((tetro.get_shape()[size1][0] != '-' && tetros[tetros.size() - 2].get_shape()[o_size1][o_size2] != '-'))
        return ;
    /* Fitting algorithm. Chekcs if it can slip and apllies it */
    if ((tetro.get_shape()[size1][0] == '-' && tetros[tetros.size() - 2].get_shape()[o_size1][o_size2] != '-')
        || (tetro.get_shape()[size1][0] != '-' && tetros[tetros.size() - 2].get_shape()[o_size1][o_size2] == '-'))
    {
        for (int i = (board.size() - 1) - size1; i < board.size(); i++)
            for (int j = add_col - size2 - 1; j < add_col; j++)
                if (board[i][j] != '-')
                    swap(board[i][j], board[i][j - 1]);
        add_col--;
        add_col2--;
        flag = 1;
    }
    // Chekcs if it can slip once again
    if ((tetro.get_shape()[size1][1] == '-' && tetros[tetros.size() - 2].get_shape()[o_size1][o_size2 - 1] != '-')
        || (tetro.get_shape()[size1][1] != '-' && tetros[tetros.size() - 2].get_shape()[o_size1][o_size2 - 1] == '-') && flag)
    {
        for (int i = (board.size() - 1) - size1; i < board.size(); i++)
            for (int j = add_col - size2 - 2; j < add_col - 1; j++)
                if (board[i][j] != '-')
                    swap(board[i][j], board[i][j - 1]);
        add_col--;
        add_col2--;
    }
}