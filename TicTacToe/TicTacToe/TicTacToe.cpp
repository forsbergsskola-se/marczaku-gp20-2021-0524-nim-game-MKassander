#include <iostream>
using namespace std;

void takeTurn(string player, string squares[9]) {
    cout << player << "'s turn" << endl;
    cout << "Enter a numer (0-8) to place your pawn" << endl;
    int response;
    cin >> response;
    if (squares[response] == "?") {
        squares[response] = player;

        if (squares[0] == player && squares[1] == player && squares[2] == player ||
            squares[3] == player && squares[4] == player && squares[5] == player ||
            squares[6] == player && squares[7] == player && squares[8] == player ||

            squares[0] == player && squares[3] == player && squares[6] == player ||
            squares[1] == player && squares[4] == player && squares[7] == player ||
            squares[2] == player && squares[5] == player && squares[8] == player ||

            squares[0] == player && squares[4] == player && squares[8] == player ||
            squares[2] == player && squares[4] == player && squares[6] == player)
        {
            cout << "You win!" << endl;
        }
    }
    else cout << "Occupied space, try again" << endl;
}

int main()
{
    string player1 = "X";
    string player2 = "O";
    bool player1Turn = true;

    string squares[9] = {"?", "?", "?", "?", "?", "?", "?", "?", "?"};

    std::cout << "Welcome to TicTacToe!\n";

    while (true)
    {
        cout << squares[0] << " " << squares[1] << " " << squares[2] << endl;
        cout << squares[3] << " " << squares[4] << " " << squares[5] << endl;
        cout << squares[6] << " " << squares[7] << " " << squares[8] << endl;

        switch (player1Turn)
        {
        case true:
            takeTurn(player1, squares);
            break;
        case false:
            takeTurn(player2, squares);
            break;
        }
        player1Turn = !player1Turn;
    }
}



/*
2 Players
Player 1: X
Player 2: O
3x3 Grid - we have not learned about Arrays, yet, but for 3x3, it can be done otherwise, too :)
players take turns choosing an empty grid cell and putting their symbol into it
player that has three of his symbols either
horizontally
vertically
diagonally wins and the game ends instantly.
make an ASCII-Art Display of the grid
 | |X
-----
O|X|
-----
O| |
implement AI-Player :)
*/
