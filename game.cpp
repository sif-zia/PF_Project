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

void EmptyCells(int cells[8][8]) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cells[i][j] = 0;
        }
    }

}

void gem(int cell, int i, int j) {

    int size = 15;

    int mid_x = (100 + 70 * (2 * i + 1)) / 2;
    int mid_y = (100 + 70 * (2 * j + 1)) / 2;
    // Black box or Empty cell is printed for 0
    if (cell == 0)
        myRect(mid_x - (size + 3), mid_y - (size + 3), mid_x + (size + 3), mid_y + (size + 3), 0, 0, 0);
    // Circle is drawn for 1
    if (cell == 1)
        myEllipse(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 255, 0, 255);
    // Triangle is drawn for 2
    else if (cell == 2) {
        myLine(mid_x, mid_y - size, mid_x + size, mid_y + size, 0, 0, 255);
        myLine(mid_x + size, mid_y + size, mid_x - size, mid_y + size, 0, 0, 255);
        myLine(mid_x - size, mid_y + size, mid_x, mid_y - size, 0, 0, 255);
    }
    // Ellipse is drawn for 3
    else if (cell == 3)
        myEllipse(mid_x - size / 2, mid_y - size, mid_x + size / 2, mid_y + size, 255, 255, 0);
    // Square is drawn for 4
    else if (cell == 4)
        myRect(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 255);
    // Cross is drawn for 5
    else if (cell == 5) {
        myLine(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 0);
        myLine(mid_x - size, mid_y + size, mid_x + size, mid_y - size, 0, 255, 0);
    }
}

void DrawGems(int cells[8][8]) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            gem(cells[i][j], i, j);
        }
    }
    
}

void randomizer(int cells[8][8]) {
    EmptyCells(cells);
    DrawGems(cells);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cells[i][j] = (rand() % 5) + 1;
}

bool isNeighbour(int selected_x, int selected_y, int cell_x, int cell_y) {
    bool flag = false;
    if ((selected_x - cell_x == 1) && (selected_y == cell_y))
        flag = true;
    else if ((cell_x - selected_x == 1) && (selected_y == cell_y))
        flag = true;
    else if ((cell_y - selected_y == 1) && (selected_x == cell_x))
        flag = true;
    else if ((selected_y - cell_y == 1) && (selected_x == cell_x))
        flag = true;
    return flag;
}

void selection(int cells[8][8], int cell_x, int cell_y, int& selected_x, int& selected_y, bool& is_selected, bool enter = false) {
    bool shouldSwap = isNeighbour(selected_x, selected_y, cell_x, cell_y);

    if (is_selected == false && enter == true) {
        selected_x = cell_x;
        selected_y = cell_y;
        is_selected = true;
    }
    else if (is_selected == true && enter == true && shouldSwap == true) {
        gem(0, selected_x, selected_y);
        gem(0, cell_x, cell_y);
        swap(cells[selected_x][selected_y], cells[cell_x][cell_y]);
        selected_x = -1;
        selected_y = -1;
        is_selected = false;
    }
    else if (is_selected == true && enter == true && shouldSwap == false) {
        selected_x = cell_x;
        selected_y = cell_y;
    }
    if (selected_x != -1) {
        int x = 50 + selected_x * (70);
        int y = 50 + selected_y * (70);
        myRect(x, y, x + 70, y + 70, 0, 255, 0);
    }

}

void MoveSelectorLeft(int& x, int& y, int& cell_x, int& cell_y) {
    if (x != 50) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
        cell_x--;
        x -= 70;
    }
}

void MoveSelectorRight(int& x, int& y, int& cell_x, int& cell_y) {
    if (x + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
        cell_x++;
        x += 70;
    }
}

void MoveSelectorUp(int& x, int& y, int& cell_x, int& cell_y) {
    if (y != 50) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
        cell_y--;
        y -= 70;
    }
}

void MoveSelectorDown(int& x, int& y, int& cell_x, int& cell_y) {
    if (y + 70 != 610) {
        myRect(x, y, x + 70, y + 70, 255, 255, 255);
        cell_y++;
        y += 70;
    }
}

int main() {

    srand(time(0));

    int keyboard_key;
    bool key_pressed, is_selected = false;
    int x = 50, y = 50, cell_x = 0, cell_y = 0, selected_x = -1, selected_y = -1;

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
            MoveSelectorLeft(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
            //gem(cells, cell_x, cell_y);
            //gem(cells, cell_x+1, cell_y);
        }
        else if (key_pressed == true && keyboard_key == 2) {
            MoveSelectorUp(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 3) {
            MoveSelectorRight(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 4) {
            MoveSelectorDown(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 5) {
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected, true);
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 6) {
            randomizer(cells);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + 70, y + 70, 255, 0, 0);
            DrawGems(cells);
        }

    }
    cin.get();
    return 0;
}