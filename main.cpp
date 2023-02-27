#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

template <typename Board>
void print_board(Board& board)
{
    const static int BOARD_SIZE = std::sqrt(board.size());

    for (int i = 0; i < board.size(); i++)
    {
        std::cout << std::setw(2) << board[i] << ':';
        if (i % BOARD_SIZE == BOARD_SIZE - 1)
            std::cout << '\n';
    }
}


template<typename Board>
bool solve(Board& board, int row, int col, int step) 
{
    const static int BOARD_SIZE = std::sqrt(board.size());

    int index = row * BOARD_SIZE + col;

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE
        || board[index] != 0)
        return false;

    board[index] = step;

    if (step == board.size())
        return true;

    ++step;

    bool solved = solve(board, row-1, col+2, step)
    || solve(board, row-1, col-2, step)
    || solve(board, row-2, col+1, step)
    || solve(board, row-2, col-1, step)
    || solve(board, row+1, col+2, step)
    || solve(board, row+1, col-2, step)
    || solve(board, row+2, col+1, step)
    || solve(board, row+2, col-1, step);

    if (!solved)
    {
        board[index] = 0;
        return false;
    }

    return true;
}

int main()
{
    const int BOARD_SIZE = 5;
    std::array<int, BOARD_SIZE * BOARD_SIZE> board{};
    int row = 0;
    int col = 0;

    std::cout << "solveable: "            << std::boolalpha << solve(board, row, col, 1) << '\n'
              << "for board size of: "    << BOARD_SIZE << '\n'
              << "starting position of: " << row << ", " << col << '\n';

    print_board(board);
    return 0;
}

