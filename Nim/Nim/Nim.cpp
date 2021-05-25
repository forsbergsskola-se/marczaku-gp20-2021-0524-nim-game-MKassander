// Nim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int matches = 24;
    string match = "|";

    while (matches > 0)
    {
        cout << "Number of matches: " << matches << endl;
        for (int i = 0; i < matches; ++i) 
            std::cout << "|";
        std::cout << std::endl;
        cout << "Enter number to pick (1-3)" << endl;

        int i;
        cin >> i;

        if (i > 0 && i < 4)
        {
            matches -= i;

            if (matches < 1)
            {
                cout << "You lost." << endl;
            }
            else
            {
                cout << "AI turn" << endl;

                if (matches == 1)
                {
                    matches -= 1;
                    cout << "Number of matches removed by AI: " << 1 << endl;
                    cout << "You won!" << endl;
                }
                else if (matches == 2)
                {
                    matches -= 1;
                    cout << "Number of matches removed by AI: " << 1 << endl;
                }

                else if (matches == 3)
                {
                    matches -= 2;
                    cout << "Number of matches removed by AI: " << 2 << endl;
                }

                else
                {
                    int r;
                    r = rand() % 3 + 1;
                    matches -= r;
                    cout << "Number of matches removed by AI: " << r << endl;
                }
            }
            
        }
        else
        {
            cout << "Invalid number." << endl;
        }
    }
}


/*2 Players
24 matches on the table
players take turns to draw matches
may draw 1, 2 or 3 matches(not more, not less)
player who has to take last match loses(alternatively: wins)
make an ASCII - Art Display of the remaining matches ||||||||||||||||
implement AI - Player :)*/