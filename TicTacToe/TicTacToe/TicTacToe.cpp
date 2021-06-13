#include <iostream>
using namespace std;

bool spacesLeft(string squares[9]) {
    int index = 0;
    while (true) {
        if (squares[index] == "?")
            return true;
        if (index == 8)
            return false;
        index++;
    }
}

bool takeTurn(string player, string squares[9]) {
    cout << player << "'s turn" << endl;
    int response = 0;
    if (player == "O")
    {
        int r;
        while (true) {
            r = rand() % 8 + 0;
            if (squares[r] == "?")
            {
                response = r;
                cout << player << " chose number " << r << endl;
                break;
            }
        }
    }
    else {
        cout << "Enter a numer (0-8) to place your pawn" << endl;
        cin >> response;
    }
    
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
            cout << player << " wins!" << endl;
            return true;
        }
        return false;
    }
    else cout << "Occupied space, try again" << endl;
    return false;
}

void printField(string squares[9]) {
    cout << squares[0] << " " << squares[1] << " " << squares[2] << endl;
    cout << squares[3] << " " << squares[4] << " " << squares[5] << endl;
    cout << squares[6] << " " << squares[7] << " " << squares[8] << endl;
}

int main()
{
    string player1 = "X";
    string player2 = "O";
    bool player1Turn = true;
    bool gameOver = false;

    string squares[9] = {"?", "?", "?", "?", "?", "?", "?", "?", "?"};

    std::cout << "Welcome to TicTacToe!\n";

    while (!gameOver)
    {
        printField(squares);

        switch (player1Turn)
        {
        case true:
            gameOver = takeTurn(player1, squares);
            break;
        case false:
            gameOver = takeTurn(player2, squares);
            break;
        }
        if (!spacesLeft(squares)) {
            cout << "Draw" << endl;
            break;
        }
        player1Turn = !player1Turn;
    }
    printField(squares);
    cout << "Game over" << endl;
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
