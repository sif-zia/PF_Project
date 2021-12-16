#include <iostream>
#include "help.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

int start_x = 400;
int start_y = 100;
int cell_size = 70;
const int cell_no = 8;
int end_x = start_x + cell_no * cell_size;
int end_y = start_y + cell_no * cell_size;

void DrawGrid() {

    //Vertical lines
    for(int x = start_x; x <= end_x; x += cell_size)
        myLine(x, start_y, x, end_y, 255);
    
    //Horizontal lines
    for (int y = start_y; y <= end_y; y += cell_size)
        myLine(start_x, y, end_x, y, 255);
}

void EmptyCells(int cells[cell_no][cell_no]) {

    for (int i = 0; i < cell_no; i++) {
        for (int j = 0; j < cell_no; j++) {
            cells[i][j] = 0;
        }
    }

}

void gem(int cell, int i, int j) {

    int size = cell_size/4;

    int mid_x = (2 * start_x + cell_size * (2 * i + 1)) / 2;
    int mid_y = (2 * start_y + cell_size * (2 * j + 1)) / 2;
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

void DrawGems(int cells[cell_no][cell_no]) {

    for (int i = 0; i < cell_no; i++) {
        for (int j = 0; j < cell_no; j++) {
            gem(cells[i][j], i, j);
        }
    }
    
}

void randomizer(int cells[cell_no][cell_no]) {
    EmptyCells(cells);
    DrawGems(cells);
    for (int i = 0; i < cell_no; i++)
        for (int j = 0; j < cell_no; j++)
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

bool isSwappingLegal(int cells[cell_no][cell_no], int selected_x, int selected_y, int  cell_x, int cell_y) {
    return true;
}

void selection(int cells[cell_no][cell_no], int cell_x, int cell_y, int& selected_x, int& selected_y, bool& is_selected, bool enter = false) {
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
        is_selected = false;
    }
    else if (is_selected == true && enter == true && shouldSwap == false) {
        selected_x = cell_x;
        selected_y = cell_y;
    }

    if (is_selected == true) {
        int green_x = start_x + selected_x * (cell_size);
        int green_y = start_y + selected_y * (cell_size);
        myRect(green_x, green_y, green_x + cell_size, green_y + cell_size, 0, 255, 0);
    }

}

void MoveSelectorLeft(int& x, int& y, int& cell_x, int& cell_y) {
    if (x != start_x) {
        myRect(x, y, x + cell_size, y + cell_size, 255, 255, 255);
        cell_x--;
        x -= cell_size;
    }
}

void MoveSelectorRight(int& x, int& y, int& cell_x, int& cell_y) {
    if (x + cell_size != end_x) {
        myRect(x, y, x + cell_size, y + cell_size, 255, 255, 255);
        cell_x++;
        x += cell_size;
    }
}

void MoveSelectorUp(int& x, int& y, int& cell_x, int& cell_y) {
    if (y != start_y) {
        myRect(x, y, x + cell_size, y + cell_size, 255, 255, 255);
        cell_y--;
        y -= cell_size;
    }
}

void MoveSelectorDown(int& x, int& y, int& cell_x, int& cell_y) {
    if (y + cell_size != end_y) {
        myRect(x, y, x + cell_size, y + cell_size, 255, 255, 255);
        cell_y++;
        y += cell_size;
    }
}

int main() {

    srand(time(0));

    int keyboard_key;
    bool key_pressed, is_selected = false;
    int x = start_x, y = start_y, cell_x = 0, cell_y = 0, selected_x = -1, selected_y = -1;

    system("@echo off");
    system("mode 800");

    int cells[cell_no][cell_no] = {};

    randomizer(cells);
    DrawGems(cells);
    DrawGrid();
    myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
    DrawGems(cells);


    while (1) {

        key_pressed = isCursorKeyPressed(keyboard_key);
        

        if (key_pressed == true && keyboard_key == 1) {
            MoveSelectorLeft(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
            //gem(cells[cell_x][cell_y], cell_x, cell_y);
            //gem(cells[cell_x+1][cell_y], cell_x+1, cell_y);
        }
        else if (key_pressed == true && keyboard_key == 2) {
            MoveSelectorUp(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 3) {
            MoveSelectorRight(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 4) {
            MoveSelectorDown(x, y, cell_x, cell_y);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 5) {
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected, true);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 6) {
            randomizer(cells);
            DrawGrid();
            selection(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }

    }
    cin.get();
    return 0;
}