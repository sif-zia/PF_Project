#include <iostream>
#include "help.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

int start_x = 400;
int start_y = 100;
int cell_size = 70;
const int cell_no = 8;
const int speed = 25;
int end_x = start_x + cell_no * cell_size;
int end_y = start_y + cell_no * cell_size;
int points = 0;

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
    int black_size = (cell_size / 2) - 3;

    int mid_x = (2 * start_x + cell_size * (2 * i + 1)) / 2;
    int mid_y = (2 * start_y + cell_size * (2 * j + 1)) / 2;
    // Black box or Empty cell is printed for 0
    if (cell == 0)
        myRect(mid_x - black_size, mid_y - black_size, mid_x + black_size, mid_y + black_size, 0, 0, 0);
    // Circle is drawn for 1
    else if (cell == 1)
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
    // Black box for 6
    else if (cell == 6)
        myRect(mid_x - black_size, mid_y - black_size, mid_x + black_size, mid_y + black_size, 0, 0, 0);
    // Concentric Circles ar drawn for 7
    else if (cell == 7) {
        myEllipse(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 255, 0, 255);
        myEllipse(mid_x - size / 2, mid_y - size / 2, mid_x + size / 2, mid_y + size / 2, 255, 0, 255);
    }
    // Star is drawn for 8
    else if (cell == 8) {
        //downward triangle
        int y = size / 3;
        myLine(mid_x - size, mid_y+y - size, mid_x + size, mid_y+y - size, 0, 0, 255);
        myLine(mid_x + size, mid_y+y - size, mid_x, mid_y+y + size, 0, 0, 255);
        myLine(mid_x, mid_y+y + size, mid_x - size, mid_y+y - size, 0, 0, 255);
        // upward triangle
        myLine(mid_x, mid_y-y - size, mid_x + size, mid_y-y + size, 0, 0, 255);
        myLine(mid_x + size, mid_y-y + size, mid_x - size, mid_y-y + size, 0, 0, 255);
        myLine(mid_x - size, mid_y-y + size, mid_x, mid_y-y - size, 0, 0, 255);
    }
    //Two perpendicular Ellipses is drawn for 9
    else if (cell == 9) {
        // horizontal ellipse
        myEllipse(mid_x - size, mid_y - size / 2, mid_x + size, mid_y + size / 2, 255, 255, 0);
        // vertical ellipse
        myEllipse(mid_x - size / 2, mid_y - size, mid_x + size / 2, mid_y + size, 255, 255, 0);
    }
    // Two Squarea are drawn for 10 one tilted and one straight
    else if (cell == 10) {
        // Normal square
        myRect(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 255);
        // Tilted square
        myLine(mid_x, mid_y - size, mid_x + size, mid_y, 0, 255, 255);
        myLine(mid_x + size, mid_y, mid_x, mid_y + size, 0, 255, 255);
        myLine(mid_x, mid_y + size, mid_x - size, mid_y, 0, 255, 255);
        myLine(mid_x - size, mid_y, mid_x, mid_y - size, 0, 255, 255);
    }
    // Asterik is drawn for 11
    else if (cell == 11) {
        //Cross
        myLine(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 0);
        myLine(mid_x - size, mid_y + size, mid_x + size, mid_y - size, 0, 255, 0);
        //Plus
        myLine(mid_x, mid_y - size, mid_x, mid_y + size, 0, 255, 0);
        myLine(mid_x - size, mid_y, mid_x + size, mid_y, 0, 255, 0);
    }
}

void DrawGems(int cells[cell_no][cell_no]) {

    for (int i = 0; i < cell_no; i++) {
        for (int j = 0; j < cell_no; j++) {
            gem(cells[i][j], i, j);
        }
    }
    
}

bool isGeneratedDuplicates(int cells[cell_no][cell_no], int i, int j) {
    bool flag = false;
    if (i != 0 && cells[i][j] == cells[i - 1][j])
        flag = true;
    if (j != 0 && cells[i][j] == cells[i][j - 1])
        flag = true;
    if (i != cell_no - 1 && cells[i][j] == cells[i + 1][j])
        flag = true;
    if (j != cell_no - 1 && cells[i][j] == cells[i][j + 1])
        flag = true;
    return flag;
}

void randomizer(int cells[cell_no][cell_no]) {
    EmptyCells(cells);
    DrawGems(cells);
    for (int i = 0; i < cell_no; i++) {
        for (int j = 0; j < cell_no; j++) {
            cells[i][j] = (rand() % 5) + 1;
            while (isGeneratedDuplicates(cells, i, j) == true) {
                cells[i][j] = (rand() % 5) + 1;
            }
        }
    }
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

bool areGemsSame(int gem1, int gem2) {
    bool samegem = false;
    if(gem1 != 0 && gem1 != 6 && gem1 != 12 && gem1 % 6 == gem2 % 6)
        samegem = true;
    return samegem;
}

bool isSwappingLegal(int cells[cell_no][cell_no], int selected_x, int selected_y, int  cell_x, int cell_y) {
    int count = 1;
    bool shouldSwap = false;
    swap(cells[selected_x][selected_y], cells[cell_x][cell_y]);
    if (selected_y == cell_y) {
        // Checking Row for atleast three consecutive duplicates
        for (int i = 1; i < cell_no; i++) {
            if (areGemsSame(cells[i][cell_y], cells[i - 1][cell_y]) == true) {
                count++;
                if (count == 3)
                    shouldSwap = true;
            }
            else
                count = 1;
        }
        count = 1;
        // Checking Column Cell_x for atleast three consecutive duplicates
        for (int i = 1; i < cell_no; i++){
            if (areGemsSame(cells[cell_x][i], cells[cell_x][i - 1]) == true) {
                count++;
                if (count == 3)
                    shouldSwap = true;
            }
            else
                count = 1;
        }
        count = 1;
        // Checking Column selected_x for atleast three consecutive duplicates
        for (int i = 1; i < cell_no; i++) {
            if (areGemsSame(cells[selected_x][i], cells[selected_x][i - 1]) == true) {
                count++;
                if (count >= 3)
                    shouldSwap = true;
            }
            else
                count = 1;
        }

    }
    else if (selected_x == cell_x) {
        // Checking column for atleast three consecutive duplicates
        for (int j = 1; j < cell_no; j++) {
            if (areGemsSame(cells[cell_x][j], cells[cell_x][j - 1]) == true) {
                count++;
                if (count >= 3)
                    shouldSwap = true;
            }
            else
                count = 1;
        }
        
        count = 1;
        // Checking cell_y row for atleast three consecutive duplicates
        for (int j = 1; j < cell_no; j++) {
            if (areGemsSame(cells[j][cell_y], cells[j - 1][cell_y]) == true) {
                count++;
                if (count >= 3)
                    shouldSwap = true;
            }
            else
                count = 1;
        }
        count = 1;
        // Checking selected_y row for atleast three consecutive duplicates
        for (int j = 1; j < cell_no; j++) {
            if (areGemsSame(cells[j][selected_y], cells[j - 1][selected_y]) == true) {
                count++;
                if (count >= 3)
                    shouldSwap = true;
            }
            else
                count = 1;
        }
    }
    swap(cells[selected_x][selected_y], cells[cell_x][cell_y]);
    return shouldSwap;
}

void deleteCell(int cells[cell_no][cell_no], int i, int j) {
    if (cells[i][j] >= 0 && cells[i][j] <= 6 || cells[i][j] == 12)
        cells[i][j] = 0;
    else if (cells[i][j] > 6 && cells[i][j] < 12)
        cells[i][j] = 6;
    else if (cells[i][j] > 12 && cells[i][j] < 18)
        cells[i][j] = 12;
}

void initiateFlameGem(int cells[cell_no][cell_no], int& pos_x, int& pos_y) {
    for (int i = pos_x - 1; i <= pos_x + 1; i++)
        for (int j = pos_y - 1; j <= pos_y + 1; j++) {
            if (i < cell_no && i >= 0 && j < cell_no && j >= 0) {
                Sleep(speed);
                deleteCell(cells, i, j);
                gem(0, i, j);
            }
        }
    if(pos_x != 0)
        pos_x--;
    pos_y = cell_no - 1;
}

void shiftCellsDown(int cells[cell_no][cell_no], int pos_x, int pos_y) {
    // Add animation in future
    for (int i = pos_y; i >= 1; i--) {
        Sleep(speed);
        cells[pos_x][i] = cells[pos_x][i - 1];
        gem(cells[pos_x][i], pos_x, i);
        gem(0, pos_x, i-1);
    }

    gem(0, pos_x, 0);
    cells[pos_x][0] = (rand() % 5) + 1;
    while (isGeneratedDuplicates(cells, pos_x, 0) == true)
        cells[pos_x][0] = (rand() % 5) + 1;
    gem(cells[pos_x][0], pos_x, 0);
}

void fillEmptyCells(int cells[cell_no][cell_no]) {

    for (int pos_x = 0; pos_x < cell_no; pos_x++)
        for (int pos_y = cell_no - 1; pos_y >= 0; pos_y--)
            if (cells[pos_x][pos_y] == 6)
                initiateFlameGem(cells, pos_x, pos_y);

    for (int pos_x = 0; pos_x < cell_no; pos_x++)
        for (int pos_y = cell_no - 1; pos_y >= 0; pos_y--)
            if (cells[pos_x][pos_y] == 0)
                shiftCellsDown(cells, pos_x, pos_y);
}

void deleteRowDuplicate(int cells[cell_no][cell_no], int row_no) {
    int count = 1;
    for (int y = 1; y < cell_no; y++) {
        if (areGemsSame(cells[row_no][y], cells[row_no][y - 1]) == true)
            count++;
        else {
            if (count == 3) { // Delete Three Consective Gems in a row
                for (int i = 1; i <= 3; i++) {
                    gem(0, row_no, y - i);
                    deleteCell(cells, row_no, y - i);
                    points += 50;
                }
            }
            else if (count >= 4) { // Delete Four or more Consective Gems in a row and adding a flame gem
                for (int i = 1; i <= count; i++) {
                    if (i == count / 2) {
                        gem(0, row_no, y - i);
                        if (cells[row_no][y - i] < 6)
                            cells[row_no][y - i] += 6;
                        else {
                            cells[row_no][y - 1] += 6;
                            deleteCell(cells, row_no, y - i);
                        }
                        gem(cells[row_no][y - i], row_no, y - i);
                        points += 50;
                    }
                    else {
                        gem(0, row_no, y - i);
                        deleteCell(cells, row_no, y - i);
                        points += 50;
                    }
                }
            }
            count = 1;
        }
    }
    if (count == 3) {  // Delete Three Consective Gems at the end of row
        for (int i = 1; i <= 3; i++) {
            gem(0, row_no, cell_no - i);
            deleteCell(cells, row_no, cell_no - i);
            points += 50;
        }
    }
    else if (count >= 4) { // Delete Four or more Consective Gems at the end of a row and adding a flame gem
        for (int i = 1; i <= count; i++) {
            if (i == count / 2) {
                gem(0, row_no, cell_no - i);
                if (cells[row_no][cell_no - i] < 6)
                    cells[row_no][cell_no - i] += 6;
                else {
                    cells[row_no][cell_no - 1] += 6;
                    deleteCell(cells, row_no, cell_no - i);
                }
                gem(cells[row_no][cell_no - i], row_no, cell_no - i);
                points += 50;
            }
            else {
                gem(0, row_no, cell_no - i);
                deleteCell(cells, row_no, cell_no - i);
                points += 50;
            }
        }
    }
}

void deleteColDuplicate(int cells[cell_no][cell_no], int col_no) {
    int count = 1;
    for (int x = 1; x < cell_no; x++) {
        if (areGemsSame(cells[x][col_no], cells[x - 1][col_no]) == true)
            count++;
        else {
            if (count == 3) { // Delete Three Consective Gems in a column
                for (int i = 1; i <= 3; i++) {
                    gem(0, x - i, col_no);
                    deleteCell(cells, x - i, col_no);
                    points += 50;
                }
            }
            else if (count >= 4) {// Delete Four or more Consective Gems in a column and adding a flame gem
                for (int i = 1; i <= count; i++) {
                    if (i == count / 2) {
                        gem(0, x - i, col_no);
                        if (cells[x - i][col_no] < 6)
                            cells[x - i][col_no] += 6;
                        else {
                            cells[x - 1][col_no] += 6;
                            deleteCell(cells, x - i, col_no);
                        }
                        gem(cells[x - i][col_no], x - i, col_no);
                        points += 50;
                    }
                    else {
                        gem(0, x - i, col_no);
                        deleteCell(cells, x - i, col_no);
                        points += 50;
                    }
                }
            }
            count = 1;
        }
    }
    if (count == 3) {// Delete Three Consective Gems at the end of column
        for (int i = 1; i <= 3; i++) {
            gem(0, cell_no - i, col_no);
            deleteCell(cells, cell_no - i, col_no);
            points += 50;
        }
    }
    else if (count >= 4) {// Delete Four or more Consective Gems at the end of a column and adding a flame gem
        for (int i = 1; i <= count; i++) {
            if (i == count / 2) {
                gem(0, cell_no - i, col_no);
                if (cells[cell_no - i][col_no] < 6)
                    cells[cell_no - i][col_no] += 6;
                else {
                    cells[cell_no - 1][col_no] += 6;
                    deleteCell(cells, cell_no - i, col_no);
                }
                gem(cells[cell_no - i][col_no], cell_no - i, col_no);
                points += 50;
            }
            else {
                gem(0, cell_no - i, col_no);
                deleteCell(cells, cell_no - i, col_no);
                points += 50;
            }
        }
    }
}

bool AnyEmptyCell(int cells[cell_no][cell_no]) {
    bool emptyCell = false;
    for (int i = 0; i < cell_no; i++)
        for (int j = 0; j < cell_no; j++)
            if (cells[i][j] == 0 || cells[i][j] == 6 || cells[i][j] == 12)
                emptyCell = true;
    return emptyCell;
}

void deleteDuplicates(int cells[cell_no][cell_no]) {
    for (int row = 0; row < cell_no; row++)
        deleteRowDuplicate(cells, row);
    for (int col = 0; col < cell_no; col++)
        deleteColDuplicate(cells, col);
}

void updateCells(int cells[cell_no][cell_no]) {
    if(AnyEmptyCell(cells) == false)
        deleteDuplicates(cells);
    fillEmptyCells(cells);
}

void selection(int cells[cell_no][cell_no], int cell_x, int cell_y, int& selected_x, int& selected_y, bool& is_selected, bool enter = false) {
    bool shouldSwap = isNeighbour(selected_x, selected_y, cell_x, cell_y);

    if (is_selected == false && enter == true) {
        selected_x = cell_x;
        selected_y = cell_y;
        is_selected = true;
    }
    else if (is_selected == true && enter == true && shouldSwap == true) {
        if (isSwappingLegal(cells, selected_x, selected_y, cell_x, cell_y) == true) {
            gem(0, selected_x, selected_y);
            gem(0, cell_x, cell_y);
            swap(cells[selected_x][selected_y], cells[cell_x][cell_y]);
            gem(cells[cell_x][cell_y], cell_x, cell_y);
            gem(cells[selected_x][selected_y], selected_x, selected_y);
            updateCells(cells);
        }
        is_selected = false;
        int green_x = start_x + selected_x * (cell_size);
        int green_y = start_y + selected_y * (cell_size);
        myRect(green_x, green_y, green_x + cell_size, green_y + cell_size, 255, 255, 255); //Draws White box to remove green box
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
        updateCells(cells);
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