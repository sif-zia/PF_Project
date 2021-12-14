#include <iostream>
#include "help.h"
using namespace std;

void DrawGrid() {
    //Border
    myLine(50, 50, 610, 50, 255);
    myLine(610, 50, 610, 610, 255);
    myLine(610, 610, 50, 610, 255);
    myLine(50, 610, 50, 50, 255);

    //Vertical lines
    for(int x = 120; x <= 540; x += 70)
        myLine(x, 50, x, 610, 255);
    
    //Horizontal lines
    for (int y = 120; y <= 540; y += 70)
        myLine(50, y, 610, y, 255);
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
        DrawGrid();

        myRect(x, y, x + 70, y + 70, 255, 0, 255);
        Sleep(50);

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