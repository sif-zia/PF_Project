#include <iostream>
#include "help.h"
using namespace std;

void DrawBorder() {
    myLine(50, 50, 900, 50, 255);
    myLine(900, 50, 900, 400, 255);
    myLine(900, 400, 50, 400, 255);
    myLine(50, 400, 50, 50, 255);
}

void MoveRectLeft(int& x, int& y) {
    if (x != 50) {
        myRect(x, y, x + 50, y + 50, 0, 0, 0);
        x -= 20;
    }
}

void MoveRectRight(int& x, int& y) {
    if (x + 50 != 900) {
        myRect(x, y, x + 50, y + 50, 0, 0, 0);
        x += 20;
    }
}

void MoveRectUp(int& x, int& y) {
    if (y != 50) {
        myRect(x, y, x + 50, y + 50, 0, 0, 0);
        y -= 20;
    }
}

void MoveRectDown(int& x, int& y) {
    if (y + 50 != 400) {
        myRect(x, y, x + 50, y + 50, 0, 0, 0);
        y += 20;
    }
}

int main() {
    int keyboard_key;
    bool key_pressed;
    int x = 470, y = 230;

    while (1) {
        DrawBorder();

        myRect(x, y, x + 50, y + 50, 255, 0, 255);
        key_pressed = isCursorKeyPressed(keyboard_key);
        if (key_pressed == true && keyboard_key == 1)
            MoveRectLeft(x, y);
        else if (key_pressed == true && keyboard_key == 2)
            MoveRectUp(x, y);
        else if (key_pressed == true && keyboard_key == 3)
            MoveRectRight(x, y);
        else if (key_pressed == true && keyboard_key == 4)
            MoveRectDown(x, y);

    }
    system("cls");
    return 0;
}