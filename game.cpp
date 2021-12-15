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

void EmptyCells() {
    int size = 20;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int mid_x = (100 + 70 * (2 * i + 1)) / 2;
            int mid_y = (100 + 70 * (2 * j + 1)) / 2;
            myRect(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 0, 0);
        }
    }

}

void randomizer(int cells[8][8]) {
    EmptyCells();
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cells[i][j] = (rand() % 5) + 1;
}

void DrawGems(int cells[8][8]) {
    int size = 15;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int mid_x = (100 + 70 * (2 * i + 1)) / 2;
            int mid_y = (100 + 70 * (2 * j + 1)) / 2;
            if (cells[i][j] == 1)
                myEllipse(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 255, 0, 255);
            else if (cells[i][j] == 2) {
                myLine(mid_x, mid_y - size, mid_x + size, mid_y + size, 0, 0, 255);
                myLine(mid_x + size, mid_y + size, mid_x - size, mid_y + size, 0, 0, 255);
                myLine(mid_x - size, mid_y + size, mid_x, mid_y - size, 0, 0, 255);
            }
            else if (cells[i][j] == 3)
                myEllipse(mid_x - size/2, mid_y - size, mid_x + size/2, mid_y + size, 255, 255, 0);
            else if (cells[i][j] == 4)
                myRect(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 255);
            else if (cells[i][j] == 5) {
                myLine(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 0);
                myLine(mid_x - size, mid_y + size, mid_x + size, mid_y - size, 0, 255, 0);
            }
        }
    }
    
}

void MoveSelectorLeft(int& x, int& y) {
    if (x != 50) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
        x -= 70;
    }
}

void MoveSelectorRight(int& x, int& y) {
    if (x + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
        x += 70;
    }
}

void MoveSelectorUp(int& x, int& y) {
    if (y != 50) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
        y -= 70;
    }
}

void MoveSelectorDown(int& x, int& y) {
    if (y + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
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
    DrawGems(cells);
    DrawGrid();
    myRect(x, y, x + 70, y + 70, 255, 0, 0);
    DrawGems(cells);


    while (1) {

        key_pressed = isCursorKeyPressed(keyboard_key);
        
        

        if (key_pressed == true && keyboard_key == 1) {
            MoveSelectorLeft(x, y);
            DrawGrid();
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 2) {
            MoveSelectorUp(x, y);
            DrawGrid();
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 3) {
            MoveSelectorRight(x, y);
            DrawGrid();
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 4) {
            MoveSelectorDown(x, y);
            DrawGrid();
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 5) {
            randomizer(cells);
            DrawGrid();
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }

    }
    cin.get();
    return 0;
}