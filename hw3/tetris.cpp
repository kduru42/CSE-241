#include "tetris.hpp"

//Constructor
Tetris::Tetris(int height, int width)
{
    b_height = height;
    b_width = width;
    set_board();
}

Tetris::Tetris(const Tetris &other)
{
    board = new char * [other.get_height()];
    for (int i = 0; i < other.get_height(); i++)
        board[i] = new char [other.get_width()];
    for (int i = 0; i < other.get_height(); i++)
        for (int j = 0; j < other.get_width(); j++)
            board[i][j] = other.board[i][j];
    b_height = other.b_height;
    b_width = other.b_width;
    tetros_size = other.tetros_size;
    set_board();
}

Tetris::~Tetris()
{
    for (int i = 0; i < b_height; i++)
        delete [] board[i];
    delete [] board;
}

/* Function to set all indexes of board with '-' charachter before any apllies */
void Tetris::set_board()
{
    board = new char * [get_height()];
    for (int i = 0; i < get_height(); i++)
        board[i] = new char [get_width()];
    for (int i = 0; i < get_height(); i++)
        for (int j = 0; j < get_width(); j++)
            board[i][j] = '-';
}

/* Function to add a tetromino to the middle-top of board */
void Tetris::add_tetromino(const Tetromino &tetro)
{
    int index;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < get_width(); j++)
            if (board[i][j] != '-')
                board[i][j] = '-';

    for (int i = 0; i < tetro.get_tetro_y_size(); i++)
    {
        index = 0;
        for (int j = (b_width - tetro.get_tetro_x_size()) / 2; j < (b_width + tetro.get_tetro_x_size()) / 2; j++) //adding tetro to the middle
        {
            board[i][j] = tetro.get_shape()[i][index]; 
            index++;
        }
    }
}

/* Function to draw board */
void Tetris::draw_board() const
{
    for (int i = 0; i < get_height(); i++)
    {
        for (int j = 0; j < get_width(); j++)
            cout << board[i][j];
        cout <<endl;
    } 
}
/* Function to animate the drop of tetromino to the bottom */
void Tetris::animate_drop(Tetromino &tetro)
{
    string rotate_dir;
    string move_dir;
    int rotate_count;
    int move_count;
    this_thread::sleep_for(chrono::milliseconds(50)); //sleeps between every draw_board
    // cout << "\033[" + to_string(get_height()) + "A";
    draw_board();
    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "Please enter rotation direction(right or left): ";
    cin >> rotate_dir;
    cout << "Please enter rotation count: ";
    cin >> rotate_count;
    cout << "Please enter movement direction(right or left): ";
    cin >> move_dir;
    cout << "Please enter movement count: ";
    cin >> move_count;
    for (int i = 0; i < rotate_count; i++)
    {
        tetro.rotate(rotate_dir);
        add_tetromino(tetro);
        // cout << "\033[" + to_string(get_height()) + "A";
        draw_board();
        this_thread::sleep_for(chrono::milliseconds(50)); 
    }
    for (int k = ((b_width - tetro.get_tetro_x_size()) / 2) + move_count; k < ((b_width - tetro.get_tetro_x_size()) / 2) + move_count + tetro.get_tetro_x_size(); k++)
    {
        if (board[tetro.get_tetro_y_size()][k] != '-')
        {
            cout << "GAME OVER!!" << endl;
            exit(1);  
        }
    }
    // It decrease index one by one and waits 50 ms
    if (move_dir == "right")
    {
        for (int j = 0; j < move_count; j++)
        {
            for (int k = 0; k < 4; k++)
                for (int l = get_width() - 1; l >= 0; l--)
                    if (board[k][l] != '-')
                        swap (board[k][l], board[k][l + 1]);
            draw_board();
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        for (int j = tetro.get_tetro_y_size() - 1; j < get_height(); j++)
        {
            int flag = 0;
            if (j != get_height() - 1)
                for (int x = j, k = ((b_width - tetro.get_tetro_x_size()) / 2) + move_count; k < ((b_width - tetro.get_tetro_x_size()) / 2) + move_count + tetro.get_tetro_x_size(); k++)
                {
                    if (board[x + 1][k] != '-')
                        flag = 1;
                }
            if (flag == 1)
                break;
            for (int k = ((b_width - tetro.get_tetro_x_size()) / 2) + move_count; k < ((b_width - tetro.get_tetro_x_size()) / 2) + move_count + tetro.get_tetro_x_size(); k++)
            {
                if (j != get_height() - 1)
                    for (int l = j; l >= 0; l--)
                        swap(board[l][k], board[l + 1][k]);
            }
            if (flag == 1)
                break;
        // cout << "\033[" + to_string(get_height()) + "A";
        draw_board();
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
    else
    {
        for (int j = 0; j < move_count; j++)
        {
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < get_width(); l++)
                    if (board[k][l] != '-')
                        swap (board[k][l], board[k][l - 1]);
            draw_board();
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        for (int j = tetro.get_tetro_y_size() - 1; j < get_height(); j++)
        {
            int flag = 0;
            if (j != get_height() - 1)
                for (int x = j, k = ((b_width - tetro.get_tetro_x_size()) / 2) - move_count; k < ((b_width - tetro.get_tetro_x_size()) / 2) - move_count + tetro.get_tetro_x_size(); k++)
                {
                    if (board[x + 1][k] != '-')
                        flag = 1;
                }
            if (flag == 1)
                break;
            for (int k = ((b_width - tetro.get_tetro_x_size()) / 2) - move_count; k < ((b_width - tetro.get_tetro_x_size()) / 2) - move_count + tetro.get_tetro_x_size(); k++)
            {
                if (j != get_height() - 1)
                    for (int l = j; l >= 0; l--)
                        swap(board[l][k], board[l + 1][k]);
            }
            if (flag == 1)
                break;
        // cout << "\033[" + to_string(get_height()) + "A";
        draw_board();
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(50));
        }
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

void Tetris::operator+= (const Tetromino &tetro)
{
    tetros_size++;
    add_tetromino(tetro);
}

Tetris& Tetris::operator=(const Tetris &other)
{
    char **temp_board;
    int height = other.get_height();
    int width = other.get_width();
    temp_board = new char * [height];
    for (int i = 0; i < height; i++)
        temp_board[i] = new char [width];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            temp_board[i][j] = other.board[i][j];
    for (int i = 0; i < b_height; i++)
        delete [] board[i];
    delete [] board;
    board = temp_board;
    tetros_size = other.tetros_size;
    b_height = other.b_height;
    b_width = other.b_width;
    return (*this);
}
