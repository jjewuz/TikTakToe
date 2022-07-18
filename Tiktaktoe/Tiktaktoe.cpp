#include <iostream>
#include <conio.h>

int main()
{
    // Memory
    enum StatusCell { EMPTY, ZERO, CROSSED };

    const int rowsQ = 3;
    const int collumnQ = 3;

    StatusCell surface[rowsQ][collumnQ];

    for (int collumn = 0; collumn < collumnQ; ++collumn) {
        for (int row = 0; row < rowsQ; ++row) {
            surface[row][collumn] = EMPTY;
        }
    }

    int currentRow = 0;
    int currentCollumn = 0;

    bool isZeroMode = true;

    // Display
    while (true) {

        for (int row = 0; row < rowsQ; ++row) {
            _putch('\n');
            for (int column = 0; column < collumnQ; ++column) {
                if (row == currentRow & column == currentCollumn) {
                    _putch(' ');
                    if (surface[row][column] == EMPTY)
                        _putch('*');
                    else if (surface[row][column] == ZERO)
                        _putch('O');
                    else if (surface[row][column] == CROSSED)
                        _putch('X');
                }
                else {
                    _putch(' ');
                    if (surface[row][column] == EMPTY)
                        _putch('.');
                    else if (surface[row][column] == ZERO)
                        _putch('o');
                    else if (surface[row][column] == CROSSED)
                        _putch('x');
                }
            }
        }
        

    // User input
        char value = _getch();
        if (value == 'w') {
            currentRow = --currentRow < 0 ? rowsQ  - 1 : currentRow;
        }
        if (value == 's') {
            currentRow = ++currentRow % rowsQ;
        }
        if (value == 'a') {
            currentCollumn = --currentCollumn < 0 ? collumnQ - 1 : currentCollumn; 
        }
        if (value == 'd') {
            currentCollumn = ++currentCollumn % collumnQ;
        }
        if (value == 'e') {

            if (surface[currentRow][currentCollumn] == EMPTY) {

                if (isZeroMode) {
                    surface[currentRow][currentCollumn] = ZERO;
                }
                else {
                    surface[currentRow][currentCollumn] = CROSSED;
                }

                isZeroMode = !isZeroMode;

            }
            
        }


        system("cls");
    }
}
