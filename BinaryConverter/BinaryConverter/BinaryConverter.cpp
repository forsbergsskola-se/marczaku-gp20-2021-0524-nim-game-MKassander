#include <iostream>
using namespace std;

const int NumberOfBits = 32;
int bits[NumberOfBits];

void normalConvert(unsigned response) {
    int i = 0;
    while (response > 0) {
        bits[i] = response % 2;
        response /= 2;
        i++;
    }

    cout << "0b ";
    int space = 4;
    for (int x = NumberOfBits - 1; x >= 0; x--) {
        cout << bits[x];
        --space;
        if (space == 0) {
            cout << " ";
            space = 4;
        }
    }

    cout << endl;
}

void binaryOperatorConvert(unsigned response) {
    cout << "0b ";
    int space = 4;
    for (int i = NumberOfBits - 1; i >= 0; i--)
    {
        int shift = response >> i;
        if (shift & 1) cout << "1";
        else cout << "0";
        --space;
        if (space == 0) {
            cout << " ";
            space = 4;
        }
    }
    cout << endl;
}

int main()
{
    cout << "Welcome to my binary converter!" << endl;
    while (true)
    {
        cout << "Enter a (positive) number to convert:" << endl;
        unsigned response;
        cin >> response;
        if (response < 0)
            cout << response << " is a negative number" << endl;
        else {
            cout << "Enter 1 to use binary operators version, or other for normal:" << endl;
            int option;
            cin >> option;
            if (option == 1)
                binaryOperatorConvert(response);
            else
                normalConvert(response);
        }
            
    }
}

/*
Write a Program that reads (cin) decimal Integer numbers (positive only) And Oututs the Binary representation of that number: 0b110

Firstly, implement the function the way we know, with division and modulo.
Secondly, implement the function using binary operations.
Tip: Both exercises will be a lot easier, if you output one character at a time!
*/
