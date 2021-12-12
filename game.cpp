#include <iostream>
#include "help.h"
using namespace std;

void DrawBorder() {
    //Border
    myLine(50, 50, 610, 50, 255);
    myLine(610, 50, 610, 610, 255);
    myLine(610, 610, 50, 610, 255);
    myLine(50, 610, 50, 50, 255);
    //Vertical lines
    myLine(120, 50, 120, 610, 255);
    myLine(190, 50, 190, 610, 255);
    myLine(260, 50, 260, 610, 255);
    myLine(330, 50, 330, 610, 255);
    myLine(400, 50, 400, 610, 255);
    myLine(470, 50, 470, 610, 255);
    myLine(540, 50, 540, 610, 255);
    //Horizontal lines
    myLine(50, 120, 610, 120, 255);
    myLine(50, 190, 610, 190, 255);
    myLine(50, 260, 610, 260, 255);
    myLine(50, 330, 610, 330, 255);
    myLine(50, 400, 610, 400, 255);
    myLine(50, 470, 610, 470, 255);
    myLine(50, 540, 610, 540, 255);
}


void MoveRectLeft(int& x, int& y) {
    if (x != 50) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        x -= 70;
    }
}

void MoveRectRight(int& x, int& y) {
    if (x + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        x += 70;
    }
}

void MoveRectUp(int& x, int& y) {
    if (y != 50) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        y -= 70;
    }
}

void MoveRectDown(int& x, int& y) {
    if (y + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        y += 70;
    }
}

int main() {
    int keyboard_key;
    bool key_pressed;
    int x = 50, y = 50;

    system("@echo off");
    system("mode 800");


    while (1) {
        DrawBorder();

        myRect(x, y, x + 70, y + 70, 255, 0, 255);

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
    cin.get();
    return 0;
}