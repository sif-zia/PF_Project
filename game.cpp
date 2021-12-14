#include <iostream>
#include "help.h"
#include <stdlib.h>
#include <ctime>
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

void randomizer(int cells[8][8]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cells[i][j] = (rand() % 5) + 1;
}

void DrawGems(int cells[8][8], int i, int j, int gem) {
    int mid_x = (100 + 70 * (2 * i + 1)) / 2;
    int mid_y = (100 + 70 * (2 * j + 1)) / 2;

    if(gem == 1)
        myEllipse(mid_x - 15, mid_y - 15, mid_x + 15, mid_y + 15, 255, 0, 255);
    else if (gem == 2) {
        myLine(mid_x, mid_y - 15, mid_x + 15, mid_y + 15, 0, 0, 255);
        myLine(mid_x + 15, mid_y + 15, mid_x - 15, mid_y + 15, 0, 0, 255);
        myLine(mid_x - 15, mid_y + 15, mid_x, mid_y - 15, 0, 0, 255);
    }
    else if(gem == 3)
        myEllipse(mid_x - 8, mid_y - 15, mid_x + 8, mid_y + 15, 255, 255, 0);
    else if(gem == 4)
        myRect(mid_x - 15, mid_y - 15, mid_x + 15, mid_y + 15, 0, 255, 255);
    else if (gem == 5) {
        myLine(mid_x - 15, mid_y - 15, mid_x + 15, mid_y + 15, 0, 255, 0);
        myLine(mid_x - 15, mid_y + 15, mid_x + 15, mid_y - 15, 0, 255, 0);
    }
}

void MoveSelectorLeft(int& x, int& y) {
    if (x != 50) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        x -= 70;
    }
}

void MoveSelectorRight(int& x, int& y) {
    if (x + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        x += 70;
    }
}

void MoveSelectorUp(int& x, int& y) {
    if (y != 50) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        y -= 70;
    }
}

void MoveSelectorDown(int& x, int& y) {
    if (y + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 0, 0, 0);
        y += 70;
    }
}

int main() {

    srand(time(0));

    int keyboard_key;
    bool key_pressed;
    int x = 50, y = 50;

    system("@echo off");
    system("mode 800");

    int cells[8][8] = {};

    randomizer(cells);


    while (1) {
        DrawGrid();

        myRect(x, y, x + 70, y + 70, 255, 0, 0);
        DrawGems(cells, 0, 0, 1);
        DrawGems(cells, 0, 1, 2);
        DrawGems(cells, 0, 2, 3);
        DrawGems(cells, 0, 3, 4);
        DrawGems(cells, 0, 4, 5);
        Sleep(50);

        key_pressed = isCursorKeyPressed(keyboard_key);

        if (key_pressed == true && keyboard_key == 1)
            MoveSelectorLeft(x, y);
        else if (key_pressed == true && keyboard_key == 2)
            MoveSelectorUp(x, y);
        else if (key_pressed == true && keyboard_key == 3)
            MoveSelectorRight(x, y);
        else if (key_pressed == true && keyboard_key == 4)
            MoveSelectorDown(x, y);

    }
    cin.get();
    return 0;
}