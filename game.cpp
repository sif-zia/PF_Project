#include <iostream>
#include "help.h"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <chrono>
#include <Windows.h>
using namespace std;

int start_x = 50;
int start_y = 100;
int cell_size = 70;
const int cell_no = 8;
const int speed = 25;
int end_x = start_x + cell_no * cell_size;
int end_y = start_y + cell_no * cell_size;
int points = 0;
auto current = std::chrono::high_resolution_clock::now();
auto printed = current;


void letters(char chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
    x1 += 5;
    x2 -= 5;
    y1 += 5;
    y2 -= 5;
    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;

    if (chr == 'A') {
        myLine(mid_x, y1, x1, y2, R);
        myLine(mid_x, y1, x2, y2, R);
        myLine(x1 + 2, mid_y + size / 2, x2 - 3, mid_y + size / 2, R, G, B);
    }
    else if (chr == 'B') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
        myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
        myLine(x1, mid_y, mid_x, mid_y, R, G, B);
        myLine(mid_x, mid_y, x2, mid_y + size / 4, R, G, B);
        myLine(x2, mid_y + size / 4, mid_x + size / 8, y2, R, G, B);
        myLine(mid_x + size / 8, y2, x1, y2, R, G, B);
    }
    else if (chr == 'C') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x2, y1, x2, y1 + size / 4, R, G, B);
        myLine(x2, y2, x2, y2 - size / 4, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'D') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, mid_x + size / 4, y1 + size / 4, R, G, B);
        myLine(mid_x + size / 4, y1 + size / 4, mid_x + size / 4, y2 - size / 4, R, G, B);
        myLine(mid_x + size / 4, y2 - size / 4, x1, y2, R, G, B);
    }
    else if (chr == 'E') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'F') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
    }
    else if (chr == 'G') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x2, y1, x2, y1 + size / 4, R, G, B);
        myLine(x2, y2, x2, y2 - size / 2, R, G, B);
        myLine(x2, y2 - size / 2, mid_x, y2 - size / 2, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'H') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
    }
    else if (chr == 'I') {
        myLine(mid_x, y1, mid_x, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'J') {
        myLine(x2, y1, x2, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x2, y2, x1, y2, R, G, B);
        myLine(x1, y2, x1, y2 - size / 2, R, G, B);
    }
    else if (chr == 'K') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, mid_y, x2, y1, R, G, B);
        myLine(x1, mid_y, x2, y2, R, G, B);
    }
    else if (chr == 'L') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'M') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, mid_x, mid_y, R, G, B);
        myLine(mid_x, mid_y, x2, y1, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == 'N') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, x2, y2, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == 'O') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == 'P') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
        myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
        myLine(x1, mid_y, mid_x, mid_y, R, G, B);

    }
    else if (chr == 'Q') {
        myLine(x1, y1, x1, y2 - 5, R, G, B);
        myLine(x1, y1, mid_x + 3, y1, R, G, B);
        myLine(mid_x + 3, y1, mid_x + 3, y2 - 5, R, G, B);
        myLine(x1, y2 - 5, mid_x + 3, y2 - 5, R, G, B);
        myLine(mid_x - 2, mid_y, mid_x + 3, y2 - 5, R, G, B);
        myLine(mid_x + 3, y2 - 5, x2, y2, R, G, B);
    }
    else if (chr == 'R') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
        myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
        myLine(x1, mid_y, mid_x, mid_y, R, G, B);
        myLine(mid_x, mid_y, x2, y2, R, G, B);
    }
    else if (chr == 'S') {
        myLine(mid_x, y1, x2, y1 + size / 2, R, G, B);
        myLine(mid_x, y1, x1, y1 + size / 2, R, G, B);
        myLine(x1, y1 + size / 2, x2, y2 - size / 2, R, G, B);
        myLine(x2, y2 - size / 2, mid_x, y2, R, G, B);
        myLine(mid_x, y2, x1, y2 - size / 2, R, G, B);
    }
    else if (chr == 'T') {
        myLine(mid_x, y1, mid_x, y2, R, G, B);
        myLine(x1, y1, x2, y1, R, G, B);
    }
    else if (chr == 'U') {
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);

    }
    else if (chr == 'V') {
        myLine(x1, y1, mid_x, y2, R, G, B);
        myLine(mid_x, y2, x2, y1, R, G, B);
    }
    else if (chr == 'W') {
        myLine(x1, y1, mid_x - size / 8, y2, R, G, B);
        myLine(mid_x - size / 8, y2, mid_x, mid_y, R, G, B);
        myLine(mid_x, mid_y, mid_x + size / 8, y2, R, G, B);
        myLine(mid_x + size / 8, y2, x2, y1, R, G, B);
    }
    else if (chr == 'X') {
        myLine(x1, y1, x2, y2, R, G, B);
        myLine(x2, y1, x1, y2, R, G, B);

    }
    else if (chr == 'Y') {
        myLine(x1, y1, mid_x, mid_y, R, G, B);
        myLine(x2, y1, x1, y2, R, G, B);
    }
    else if (chr == 'Z') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x2, y1, x1, y2, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == '.') {
        myRect(x2, y2 - size / 8, mid_x + size / 4, y2, R, G, B);
    }
    else if (chr == ',') {
        myRect(x2, y2 - size / 3, mid_x + size / 4, y2 - size / 6, R, G, B);
        myLine(x2, y2 - size / 3, x2, y2, R);
        myLine(x2, y2, mid_x + size / 4, y2, R);
    }
    else if (chr == '!') {
        myRect(mid_x - size / 8, y1, mid_x - 1, y2 - size / 3, R, G, B);
        myRect(mid_x - size / 8, y2 - size / 8, mid_x, y2, R, G, B);
    }
    else if (chr == ':') {
        myRect(x2, y2 - 20, mid_x + size / 4, y2 - 16, R, G, B);
        myRect(x2, y2 - 4, mid_x + size / 4, y2, R, G, B);
    }
    else if (chr == '1') {
        myLine(x1, mid_y - size / 2, mid_x, y1, R, G, B);
        myLine(mid_x, y1, mid_x, y2, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == '2') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x2, y1, x2, mid_y, R, G, B);
        myLine(x2, mid_y, x1, mid_y, R, G, B);
        myLine(x1, mid_y, x1, y2, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == '3') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x2, y1, x2, mid_y, R, G, B);
        myLine(x2, mid_y, x1, mid_y, R, G, B);
        myLine(x2, mid_y, x2, y2, R, G, B);
        myLine(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '4') {
        myLine(x1, y1, x1, mid_y, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
        myLine(mid_x + size / 6, y1, mid_x + size / 6, y2, R, G, B);
    }
    else if (chr == '5') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, y1, x1, mid_y, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
        myLine(x2, mid_y, x2, y2, R, G, B);
        myLine(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '6') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
        myLine(x2, mid_y, x2, y2, R, G, B);
        myLine(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '7') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == '8') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
        myLine(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '9') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, y1, x1, mid_y, R, G, B);
        myLine(x1, mid_y, x2, mid_y, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
        myLine(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '-')
        myRect(x1-5, y1-5, x2+5, y2+5, R, G, B);
}

void Capitalizer(char text[]) {
    for (int i = 0; i < strlen(text); i++)
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] -= 32;
}

void drawText(int size, int start_x, int start_y, int R, int G, int B, char text[], bool& isNum, int num = 0) {
    int idx = 0;
    int idx_x = 0;
    int idx_y = 0;
    int x1, x2, y1, y2;
    int digit_count = 0;
    int len = strlen(text);

    if (isNum == true) {
        int reverse_num = 0;
        int i;

        for (; num > 0; num /= 10, digit_count++)
            reverse_num = (reverse_num * 10) + num % 10;

        for (i = len; i - len < digit_count; i++, reverse_num /= 10)
            text[i] = (reverse_num % 10) + 48;

        text[i] = '\0';
        isNum = false;
    }

    Capitalizer(text);

    for (idx = 0; idx < strlen(text); idx++)
    {
        x1 = start_x + size * idx_x;
        x2 = start_x + size * (idx_x + 1);

        if (x2 > 1585 - size) {
            idx_y++;
            idx_x = 0;
            x1 = start_x + size * idx_x;
            x2 = start_x + size * (idx_x + 1);

        }

        y1 = start_y + 2 * size * idx_y;
        y2 = start_y + 2 * size * (idx_y + 1);
        letters(text[idx], x1, x2, y1, y2, size, R, G, B);
        idx_x++;
    }

}

void printTime(int mins, int secs, bool time_out) {
    int size = 25;
    int R, G, B;
    R = G = B = 255;
    int timer_x = start_x + (cell_no + 1) * (cell_size), x1, x2, y1, y2;
    int timer_y = start_y + 2 * (cell_size);

    y1 = timer_y;
    y2 = timer_y + 2 * size;
    if (time_out == false) {

        char text[75] = "Time Remaining: ";
        Capitalizer(text);
        int i = 0;

        for (; i < strlen(text); i++) {
            x1 = timer_x + size * i;
            x2 = timer_x + size * (i + 1);
            letters(text[i], x1, x2, y1, y2, size, R, G, B);
        }
        x1 = timer_x + size * i;
        x2 = timer_x + size * (i + 1);
        letters('-', x1, x2, y1, y2, size);
        letters((mins / 10) + 48, x1, x2, y1, y2, size, R, G, B);
        i++;
        x1 = timer_x + size * i;
        x2 = timer_x + size * (i + 1);
        letters('-', x1, x2, y1, y2, size);
        letters((mins % 10) + 48, x1, x2, y1, y2, size, R, G, B);
        i++;
        x1 = timer_x + size * i;
        x2 = timer_x + size * (i + 1);
        letters('-', x1, x2, y1, y2, size);
        letters(':', x1, x2, y1, y2, size, R, G, B);
        i++;
        x1 = timer_x + size * i;
        x2 = timer_x + size * (i + 1);
        letters('-', x1, x2, y1, y2, size);
        letters((secs / 10) + 48, x1, x2, y1, y2, size, R, G, B);
        i++;
        x1 = timer_x + size * i;
        x2 = timer_x + size * (i + 1);
        letters('-', x1, x2, y1, y2, size);
        letters((secs % 10) + 48, x1, x2, y1, y2, size, R, G, B);
    }
    else {
        char text[] = "Game Over! Press Escape to Exit!";
        Capitalizer(text); int i = 0;
        for (; i < strlen(text); i++) {
            x1 = timer_x + size * i;
            x2 = timer_x + size * (i + 1);
            letters('-', x1, x2, y1, y2, size);
            letters(text[i], x1, x2, y1, y2, size, R, G, B);
        }
    }
}

bool timer(int& mins, int& secs, bool& updated, bool start_timer = false) {
    bool time_out = false;

    if (updated == true)
        updated = false;

    if (start_timer = true)
        current = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> time_passed = current - printed;

    if (time_passed.count() >= 1) { // When one second has passed execute the following condition

        if (secs == 0 && mins == 0) // if secs and mins both are zero return true
            time_out = true;
        else if (secs == 0 && mins > 0) {
            mins--;  // When secs is zero and mins is greater than zero reduce 1 min
            secs = 59; // and set secs to 59
        }
        else if (secs > 0) // When secs is greater than zero just decrement it
            secs--;

        printed = current;
        updated = true;
    }

    if (updated == true)
        printTime(mins, secs, time_out);

    current = std::chrono::high_resolution_clock::now();

    return time_out;
}

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
            if (cells[i][j] < 6)
                cells[i][j] = 0;
        }
    }

}

void gem(int cell, int i, int j) {

    int size = cell_size/4;
    int black_size = (cell_size / 2) - 3;

    if (i < 0 || i >= cell_no || j < 0 || j >= cell_no)
        return;

    int mid_x = (2 * start_x + cell_size * (2 * i + 1)) / 2;
    int mid_y = (2 * start_y + cell_size * (2 * j + 1)) / 2;
    // Black box or Empty cell is printed for 0
    if (cell%6 == 0)
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
    // Concentric Circles are drawn for 7
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
    // Concentric Circles with plus are drawn for 13
    else if (cell == 13) {
        //Circles
        myEllipse(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 255, 0, 255);
        myEllipse(mid_x - size / 2, mid_y - size / 2, mid_x + size / 2, mid_y + size / 2, 255, 0, 255);
        //Plus
        myLine(mid_x, mid_y - size, mid_x, mid_y + size, 255, 0, 255);
        myLine(mid_x - size, mid_y, mid_x + size, mid_y, 255, 0, 255);
    }
    // Star inside a circle is drawn for 14
    else if (cell == 14) {
        int y = size / 3;
        //Circle
        myEllipse(mid_x - size - y, mid_y - size - y, mid_x + size + y, mid_y + size + y, 0, 0, 255);
        //downward triangle
        myLine(mid_x - size, mid_y + y - size, mid_x + size, mid_y + y - size, 0, 0, 255);
        myLine(mid_x + size, mid_y + y - size, mid_x, mid_y + y + size, 0, 0, 255);
        myLine(mid_x, mid_y + y + size, mid_x - size, mid_y + y - size, 0, 0, 255);
        // upward triangle
        myLine(mid_x, mid_y - y - size, mid_x + size, mid_y - y + size, 0, 0, 255);
        myLine(mid_x + size, mid_y - y + size, mid_x - size, mid_y - y + size, 0, 0, 255);
        myLine(mid_x - size, mid_y - y + size, mid_x, mid_y - y - size, 0, 0, 255);
    }
    //Two perpendicular Ellipses with a plus is drawn for 15
    else if (cell == 15) {
        // horizontal ellipse
        myEllipse(mid_x - size, mid_y - size / 2, mid_x + size, mid_y + size / 2, 255, 255, 0);
        // vertical ellipse
        myEllipse(mid_x - size / 2, mid_y - size, mid_x + size / 2, mid_y + size, 255, 255, 0);
        //Plus
        myLine(mid_x, mid_y - size, mid_x, mid_y + size, 255, 255, 0);
        myLine(mid_x - size, mid_y, mid_x + size, mid_y, 255, 255, 0);
    }
    // Two Squarea with a plus are drawn for 16 one tilted and one straight
    else if (cell == 16) {
        // Normal square
        myRect(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 255);
        // Tilted square
        myLine(mid_x, mid_y - size, mid_x + size, mid_y, 0, 255, 255);
        myLine(mid_x + size, mid_y, mid_x, mid_y + size, 0, 255, 255);
        myLine(mid_x, mid_y + size, mid_x - size, mid_y, 0, 255, 255);
        myLine(mid_x - size, mid_y, mid_x, mid_y - size, 0, 255, 255);
        //Plus
        myLine(mid_x, mid_y - size, mid_x, mid_y + size, 0, 255, 255);
        myLine(mid_x - size, mid_y, mid_x + size, mid_y, 0, 255, 255);
    }
    // Asterik with a circle is drawn for 17
    else if (cell == 17) {
        //Circle
        myEllipse(mid_x - size, mid_y - size, mid_x + size, mid_y + size, 0, 255, 0);
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
            if (cells[i][j] == 0) {
                cells[i][j] = (rand() % 5) + 1;
                while (isGeneratedDuplicates(cells, i, j) == true) {
                    cells[i][j] = (rand() % 5) + 1;
                }
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
        // Checking column for atleast three consecutive duplicates
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
        // Checking row Cell_x for atleast three consecutive duplicates
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
        // Checking row selected_x for atleast three consecutive duplicates
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

void deleteGem(int cells[cell_no][cell_no], int i, int j) {
    if (cells[i][j] >= 0 && cells[i][j] < 6)
        cells[i][j] = 0;
    else if (cells[i][j] > 6 && cells[i][j] < 12)
        cells[i][j] = 6;
    else if (cells[i][j] > 12 && cells[i][j] < 18)
        cells[i][j] = 12;

}

void initiateFlameGem(int cells[cell_no][cell_no], int& pos_x, int& pos_y) {
    deleteCell(cells, pos_x, pos_y);
    for (int i = pos_x - 1; i <= pos_x + 1; i++)
        for (int j = pos_y - 1; j <= pos_y + 1; j++) {
            if (i < cell_no && i >= 0 && j < cell_no && j >= 0) {
                Sleep(speed);
                deleteGem(cells, i, j);
                gem(0, i, j);
            }
        }
    if (pos_x != 0)
        pos_x--;
    pos_y = cell_no - 1;
}

void initiateDestroyerGem(int cells[cell_no][cell_no], int& pos_x, int& pos_y) {

    deleteCell(cells, pos_x, pos_y);
    for (int x = 0; x < cell_no; x++) {
        Sleep(speed / 2);
        deleteGem(cells, x, pos_y);
        gem(0, x, pos_y);
    }
    for (int y = 0; y < cell_no; y++) {
        Sleep(speed / 2);
        deleteCell(cells, pos_x, y);
        gem(0, pos_x, y);
    }

    pos_x = 0;
    pos_y = cell_no - 1;
}

void shiftGemsDown(int cells[cell_no][cell_no], int pos_x, int pos_y) {
    // Add animation in future
    for (int i = pos_y; i >= 1; i--) {
        Sleep(speed);
        cells[pos_x][i] = cells[pos_x][i - 1];
        gem(cells[pos_x][i], pos_x, i);
        gem(0, pos_x, i - 1);
    }

    gem(0, pos_x, 0);
    cells[pos_x][0] = (rand() % 5) + 1;
    while (isGeneratedDuplicates(cells, pos_x, 0) == true)
        cells[pos_x][0] = (rand() % 5) + 1;
    gem(cells[pos_x][0], pos_x, 0);
}

void fillEmptyCells(int cells[cell_no][cell_no]) {

    for (int pos_x = 0; pos_x < cell_no; pos_x++) {
        for (int pos_y = cell_no - 1; pos_y >= 0; pos_y--) {
            if (cells[pos_x][pos_y] == 6)
                initiateFlameGem(cells, pos_x, pos_y);
            else if (cells[pos_x][pos_y] == 12)
                initiateDestroyerGem(cells, pos_x, pos_y);
        }
    }

    for (int pos_x = 0; pos_x < cell_no; pos_x++)
        for (int pos_y = cell_no - 1; pos_y >= 0; pos_y--)
            if (cells[pos_x][pos_y] == 0)
                shiftGemsDown(cells, pos_x, pos_y);
}

bool isVerticalElbowFormed(int cells[cell_no][cell_no], int x, int y, int& elbow_x, int& elbow_y) {
    bool elbowfound = false;
    for (int i = y; i >= y - 2; i--) {
        if (areGemsSame(cells[x][i], cells[x + 1][i]) == true && areGemsSame(cells[x + 1][i], cells[x + 2][i]) == true) {
            elbowfound = true;
            elbow_x = x;
            elbow_y = i;
            deleteCell(cells, x + 1, i);
            gem(0, x + 1, i);
            deleteCell(cells, x + 2, i);
            gem(0, x + 2, i);
            points += 100;
        }
        if (areGemsSame(cells[x][i], cells[x - 1][i]) == true && areGemsSame(cells[x - 1][i], cells[x - 2][i]) == true && !elbowfound) {
            elbowfound = true;
            elbow_x = x;
            elbow_y = i;
            deleteCell(cells, x - 1, i);
            gem(0, x - 1, i);
            deleteCell(cells, x - 2, i);
            gem(0, x - 2, i);
            points += 100;
        }
    }
    
    if (areGemsSame(cells[x - 1][y - 2], cells[x][y - 2]) == true && areGemsSame(cells[x][y - 2], cells[x + 1][y - 2]) == true){
        elbowfound = true;
        elbow_x = x;
        elbow_y = y-2;
        deleteCell(cells, x - 1, y - 2);
        gem(0, x - 1, y - 2);
        deleteCell(cells, x + 1, y - 2);
        gem(0, x + 1, y - 2);
        points += 100;
    }
    if (areGemsSame(cells[x - 1][y - 2], cells[x][y - 2]) == true && areGemsSame(cells[x][y - 2], cells[x + 1][y - 2]) == true && !elbowfound) {
        elbowfound = true;
        elbow_x = x;
        elbow_y = y;
        deleteCell(cells, x - 1, y);
        gem(0, x - 1, y);
        deleteCell(cells, x + 1, y);
        gem(0, x + 1, y);
        points += 100;
    }
    return elbowfound;
}

void deleteColDuplicate(int cells[cell_no][cell_no], int col) {
    int count = 1;
    int elbow_x, elbow_y;
    int Gem;
    for (int y = 1; y < cell_no; y++) {
        if (areGemsSame(cells[col][y], cells[col][y - 1]) == true)
            count++;
        else {
            if (count == 3) { // Delete Three Consective Gems in a row
                if (isVerticalElbowFormed(cells, col, y - 1, elbow_x, elbow_y) == true) {
                    Gem = cells[elbow_x][elbow_y];
                    for (int i = 1; i <= 3; i++) {
                        gem(0, col, y - i);
                        deleteCell(cells, col, y - i);
                        points += 50;
                    }
                    if(Gem < 6)
                        cells[elbow_x][elbow_y] = Gem + 12;
                    else {
                        Gem %= 6;
                        cells[elbow_x][elbow_y] = Gem + 12;
                    }
                }
                else {
                    for (int i = 1; i <= 3; i++) {
                        gem(0, col, y - i);
                        deleteCell(cells, col, y - i);
                        points += 50;
                    }
                }
            }
            else if (count >= 4) { // Delete Four or more Consective Gems in a row and adding a flame gem
                bool flame_inserted = false;
                for (int i = 1; i <= count; i++) {
                    if (cells[col][y - i] < 6 && flame_inserted == false) {
                        gem(0, col, y - i);
                        cells[col][y - i] += 6;
                        gem(cells[col][y - i], col, y - i);
                        points += 50;
                        flame_inserted = true;
                    }
                    else {
                        gem(0, col, y - i);
                        deleteCell(cells, col, y - i);
                        points += 50;
                    }
                }
            }
            count = 1;
        }
    }
    if (count == 3) {  // Delete Three Consective Gems at the end of row
        if (isVerticalElbowFormed(cells, col, cell_no - 1, elbow_x, elbow_y) == true) {
            Gem = cells[elbow_x][elbow_y];
            for (int i = 1; i <= 3; i++) {
                gem(0, col, cell_no - i);
                deleteCell(cells, col, cell_no - i);
                points += 50;
            }
            if (Gem < 6)
                cells[elbow_x][elbow_y] = Gem + 12;
            else {
                Gem %= 6;
                cells[elbow_x][elbow_y] = Gem + 12;
            }
        }
        else {
            for (int i = 1; i <= 3; i++) {
                gem(0, col, cell_no - i);
                deleteCell(cells, col, cell_no - i);
                points += 50;
            }
        }
    }
    else if (count >= 4) { // Delete Four or more Consective Gems at the end of a row and adding a flame gem
        bool flame_inserted = false;
        for (int i = 1; i <= count; i++) {
            if (cells[col][cell_no - i] < 6 && flame_inserted == false) {
                gem(0, col, cell_no - i);
                cells[col][cell_no - i] += 6;
                gem(cells[col][cell_no - i], col, cell_no - i);
                points += 50;
                flame_inserted = true;
            }
            else {
                gem(0, col, cell_no - i);
                deleteCell(cells, col, cell_no - i);
                points += 50;
            }
        }
    }
}

bool isHorizontalElbowFormed(int cells[cell_no][cell_no], int x, int y, int& elbow_x, int& elbow_y) {
    bool elbowfound = false;
    for (int i = x; i >= x - 2; i--) {
        if (areGemsSame(cells[i][y], cells[i][y+1]) == true && areGemsSame(cells[i][y+1], cells[i][y+2]) == true) {
            elbowfound = true;
            elbow_x = x;
            elbow_y = i;
            deleteCell(cells, i, y+1);
            gem(0, i, y + 1);
            deleteCell(cells, i, y+2);
            gem(0, i, y + 2);
            points += 100;
        }
        if (areGemsSame(cells[i][y], cells[i][y - 1]) == true && areGemsSame(cells[i][y - 1], cells[i][y - 2]) == true && !elbowfound) {
            elbowfound = true;
            elbow_x = x;
            elbow_y = i;
            deleteCell(cells, i, y - 1);
            gem(0, i, y - 1);
            deleteCell(cells, i, y - 2);
            gem(0, i, y - 2);
            points += 100;
        }
    }
    if (areGemsSame(cells[x - 2][y - 1], cells[x - 2][y]) == true && areGemsSame(cells[x - 2][y], cells[x - 2][y + 1]) == true){
        elbowfound = true;
        elbow_x = x - 2;
        elbow_y = y;
        deleteCell(cells, x - 2, y - 1);
        gem(0, x - 2, y - 1);
        deleteCell(cells, x - 2, y + 1);
        gem(0, x - 2, y + 1);
        points += 100;
    }
    if (areGemsSame(cells[x][y - 1], cells[x][y]) == true && areGemsSame(cells[x][y], cells[x][y + 1]) == true && !elbowfound) {
        elbowfound = true;
        elbow_x = x;
        elbow_y = y;
        deleteCell(cells, x, y - 1);
        gem(0, x, y - 1);
        deleteCell(cells, x, y + 1);
        gem(0, x, y + 1);
        points += 100;
    }
    return elbowfound;
}

void deleteRowDuplicate(int cells[cell_no][cell_no], int row) {
    int count = 1;
    int elbow_x, elbow_y;
    int Gem;
    for (int x = 1; x < cell_no; x++) {
        if (areGemsSame(cells[x][row], cells[x - 1][row]) == true)
            count++;
        else {
            if (count == 3) { // Delete Three Consective Gems in a column
                if (isHorizontalElbowFormed(cells, x - 1, row, elbow_x, elbow_y)) {
                    Gem = cells[elbow_x][elbow_y];
                    for (int i = 1; i <= 3; i++) {
                        gem(0, x - i, row);
                        deleteCell(cells, x - i, row);
                        points += 50;
                    }
                    if (Gem < 6)
                        cells[elbow_x][elbow_y] = Gem + 12;
                    else {
                        Gem %= 6;
                        cells[elbow_x][elbow_y] = Gem + 12;
                    }

                }
                else {
                    for (int i = 1; i <= 3; i++) {
                        gem(0, x - i, row);
                        deleteCell(cells, x - i, row);
                        points += 50;
                    }
                }
            }
            else if (count >= 4) {// Delete Four or more Consective Gems in a column and adding a flame gem
                bool flame_inserted = false;
                for (int i = 1; i <= count; i++) {
                    if (cells[x - i][row] < 6 && flame_inserted == false) {
                        gem(0, x - i, row);
                        cells[x - i][row] += 6;
                        gem(cells[x - i][row], x - i, row);
                        points += 50;
                        flame_inserted = true;
                    }
                    else {
                        gem(0, x - i, row);
                        deleteCell(cells, x - i, row);
                        points += 50;
                    }
                }
            }
            count = 1;
        }
    }
    if (count == 3) {// Delete Three Consective Gems at the end of column
        if (isHorizontalElbowFormed(cells, cell_no - 1, row, elbow_x, elbow_y)) {
            Gem = cells[elbow_x][elbow_y];
            for (int i = 1; i <= 3; i++) {
                gem(0, cell_no - i, row);
                deleteCell(cells, cell_no - i, row);
                points += 50;
            }
            if (Gem < 6)
                cells[elbow_x][elbow_y] = Gem + 12;
            else {
                Gem %= 6;
                cells[elbow_x][elbow_y] = Gem + 12;
            }

        }
        else {
            for (int i = 1; i <= 3; i++) {
                gem(0, cell_no - i, row);
                deleteCell(cells, cell_no - i, row);
                points += 50;
            }
        }
    }
    else if (count >= 4) {// Delete Four or more Consective Gems at the end of a column and adding a flame gem
        bool flame_inserted = false;
        for (int i = 1; i <= count; i++) {
            if (cells[cell_no - i][row] < 6 && flame_inserted == false) {
                gem(0, cell_no - i, row);
                cells[cell_no - i][row] += 6;
                gem(cells[cell_no - i][row], cell_no - i, row);
                points += 50;
                flame_inserted = true;
            }
            else {
                gem(0, cell_no - i, row);
                deleteCell(cells, cell_no - i, row);
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
    for (int col = 0; col < cell_no; col++)
        deleteColDuplicate(cells, col);
    for (int row = 0; row < cell_no; row++)
        deleteRowDuplicate(cells, row);
    
}

void updateCells(int cells[cell_no][cell_no]) {
    if(AnyEmptyCell(cells) == false)
        deleteDuplicates(cells);
    fillEmptyCells(cells);
}

void selectionAndswapping(int cells[cell_no][cell_no], int cell_x, int cell_y, int& selected_x, int& selected_y, bool& is_selected, bool enter = false) {
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
        int green_x = start_x + selected_x * (cell_size);
        int green_y = start_y + selected_y * (cell_size);
        myRect(green_x, green_y, green_x + cell_size, green_y + cell_size, 255, 255, 255); //Draws White box to remove green box
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
    bool key_pressed, is_selected = false, isNum = true, updated = false;
    int x = start_x, y = start_y, cell_x = 0, cell_y = 0, selected_x = -1, selected_y = -1, mins = 1, secs = 0;

    system("@echo off");
    system("mode 800");

    int cells[cell_no][cell_no] = {};

    randomizer(cells);
    DrawGems(cells);
    DrawGrid();
    myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
    DrawGems(cells);
    
    bool time_out = timer(mins, secs, updated, true);

    while (time_out == false) {
        updateCells(cells);
        time_out = timer(mins, secs, updated);
        key_pressed = isCursorKeyPressed(keyboard_key);
        

        if (key_pressed == true && keyboard_key == 1) {
            MoveSelectorLeft(x, y, cell_x, cell_y);
            DrawGrid();
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 2) {
            MoveSelectorUp(x, y, cell_x, cell_y);
            DrawGrid();
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 3) {
            MoveSelectorRight(x, y, cell_x, cell_y);
            DrawGrid();
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 4) {
            MoveSelectorDown(x, y, cell_x, cell_y);
            DrawGrid();
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 5) {
            DrawGrid();
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected, true);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 6) {
            randomizer(cells);
            DrawGrid();
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
        }
        else if (key_pressed == true && keyboard_key == 7) {
            break;
        }

    }
    key_pressed = isCursorKeyPressed(keyboard_key);
    while (key_pressed != true && keyboard_key != 7)
        key_pressed = isCursorKeyPressed(keyboard_key);

    cin.get();
    return 0;
}