#include <iostream>
#include "help.h"
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <chrono>
using namespace std;

int start_x = 50;
int start_y = 100;
int cell_size = 70;
const int cell_no = 8;
const int speed = 25;
int end_x = start_x + cell_no * cell_size;
int end_y = start_y + cell_no * cell_size;
int points = 0, Points = 0;
int idle_tick = 0;
int hint_x = 0, hint_y = 0;
auto current = std::chrono::high_resolution_clock::now();
auto printed = current;
bool isNum = true, ext = false;
char pre_rec_msgs[9][50] = { "---------------------------------",   //0
                             "Press Enter to Start!",               //1
                             "Time Remaining: --:--",               //2
                             "Points: ",                            //3
                             "Game Over! Press Escape to Continue!",//4
                             "Congrats! You Scored: ",              //5
                             "You Failed! Better luck next time!",  //6
                             "Congrats! You reached the goal!",     //7
                             "Your Goal: "                          //8
};

void menu();

void mode_menu();

void pause_menu();

void time_menu();

bool hint(int cells[cell_no][cell_no], bool movement);

void lettersnNumbers(char chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
    x1 += 5;
    x2 -= 5;
    y1 += 5;
    y2 -= 5;
    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;

    if (chr == 'A') {
        myLine(mid_x, y1, x1, y2, R, G, B);
        myLine(mid_x, y1, x2, y2, R, G, B);
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
    else if (chr == '0') {
        myLine(x1, y1, x2, y1, R, G, B);
        myLine(x1, y1, x1, y2, R, G, B);
        myLine(x2, y1, x2, y2, R, G, B);
        myLine(x1, y2, x2, y2, R, G, B);
        myLine(x2, y1, x1, y2, R, G, B);
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
        myRect(x1-5, y1-5, x2+5, y2+5, 0, 0, 0);
}

void Capitalizer(char text[]) {
    for (int i = 0; i < strlen(text); i++)
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] -= 32;
}

void drawText(int size, int start_x, int start_y, int R, int G, int B, char text[], bool isNum = false, int num = 0) {
    int idx = 0;
    int idx_x = 0;
    int idx_y = 0;
    int x1, x2, y1, y2;
    int digit_count = 0;
    int len = strlen(text);
    char temp[100];

    strcpy_s(temp, text);
    if (isNum == true) {
        int reverse_num = 0;
        int i;

        for (; num > 0; num /= 10, digit_count++)
            reverse_num = (reverse_num * 10) + num % 10;

        for (i = len; i - len < digit_count; i++, reverse_num /= 10)
            temp[i] = (reverse_num % 10) + 48;

        temp[i] = '\0';
    }

    Capitalizer(temp);

    for (idx = 0; idx < strlen(temp); idx++)
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
        lettersnNumbers(temp[idx], x1, x2, y1, y2, size, R, G, B);
        idx_x++;
    }

}

void game_over(bool point_based, int mins, int secs, int points, bool goal_reached = false) {
    myRect(50, 100, 1810, 880, 0, 0, 0);
    if (point_based == false) {
        drawText(35, 200, 200, 100, 100, 255, pre_rec_msgs[5], true, points);
        drawText(25, 200, 300, 100, 100, 255, pre_rec_msgs[4]);
    }
    else if (point_based == true && goal_reached == false) {
        drawText(35, 200, 200, 255, 100, 100, pre_rec_msgs[6]);
        drawText(25, 200, 300, 255, 100, 100, pre_rec_msgs[4]);
    }
    else if (point_based == true && goal_reached == true) {
        drawText(35, 200, 200, 100, 255, 100, pre_rec_msgs[7]);
        drawText(25, 200, 300, 100, 255, 100, pre_rec_msgs[4]);
    }
}

void printPoints(int Points) {
    int size = 25;
    int R, G, B;
    R = G = B = 255;
    int points_x = start_x + (cell_no + 1) * (cell_size);
    int points_y = start_y + 3 * (cell_size);
    drawText(25, points_x, points_y, 0, 0, 0, pre_rec_msgs[0]);
    drawText(25, points_x, points_y, R, G, B, pre_rec_msgs[3], true, Points);
}

void printGoal(int Points) {
    int size = 25;
    int R, G, B;
    R = G = B = 255;
    int points_x = start_x + (cell_no + 1) * (cell_size);
    int points_y = start_y + 4 * (cell_size);
    drawText(25, points_x, points_y, 0, 0, 0, pre_rec_msgs[0]);
    drawText(25, points_x, points_y, R, G, B, pre_rec_msgs[8], true, Points);
}

void printTime(int mins, int secs) {
    int size = 25;
    int R, G, B;
    R = G = B = 255;
    int timer_x = start_x + (cell_no + 1) * (cell_size);
    int timer_y = start_y + 2 * (cell_size);
    char temp[50];
    
    strcpy_s(temp, pre_rec_msgs[2]);
    drawText(size, timer_x, timer_y, R, G, B, temp);
    int len = strlen(temp) - 5;
    temp[len] = mins / 10 + 48;
    temp[len+1] = mins % 10 + 48;
    temp[len + 2] = ':';
    temp[len+3] = secs / 10 + 48;
    temp[len+4] = secs % 10 + 48;
    temp[len+5] = '\0';
    drawText(size, timer_x, timer_y, R, G, B, temp);
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

        idle_tick++;

        printed = current;
        updated = true;
    }

    if (updated == true)
        printTime(mins, secs);

    current = std::chrono::high_resolution_clock::now();

    return time_out;
}

void stopwatch(int& mins, int& secs, bool& updated, bool start_timer = false) {

    if (updated == true)
        updated = false;

    if (start_timer = true)
        current = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> time_passed = current - printed;

    if (time_passed.count() >= 1) { // When one second has passed execute the following condition

        secs++;
        if (secs == 60)
            mins++, secs = 0;

        idle_tick++;

        printed = current;
        updated = true;
    }

    if (updated == true)
        printTime(mins, secs);

    current = std::chrono::high_resolution_clock::now();
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

bool isElbowFormed(int cells[cell_no][cell_no], int x, int y, int& elbow_x, int& elbow_y) {
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
    if (areGemsSame(cells[x - 1][y], cells[x][y]) == true && areGemsSame(cells[x][y], cells[x + 1][y]) == true && !elbowfound) {
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
    for (int y = 1; y <= cell_no; y++) {
        if (areGemsSame(cells[col][y], cells[col][y - 1]) == true && y != cell_no)
            count++;
        else {
            if (count == 3) { // Delete Three Consective Gems in a column
                hint(cells, true);
                if (isElbowFormed(cells, col, y - 1, elbow_x, elbow_y) == true) {
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
                    gem(cells[elbow_x][elbow_y], elbow_x, elbow_y);
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
                hint(cells, true);
                bool flame_inserted = false;
                for (int i = 1; i <= count; i++) {
                    if (cells[col][y - i] < 6 && flame_inserted == false) {
                        gem(0, col, y - i);
                        cells[col][y - i] %= 6;
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
}

void deleteRowDuplicate(int cells[cell_no][cell_no], int row) {
    int count = 1;
    for (int x = 1; x <= cell_no; x++) {
        if (areGemsSame(cells[x][row], cells[x - 1][row]) == true && x != cell_no)
            count++;
        else {
            if (count == 3) { // Delete Three Consective Gems in a row
                hint(cells, true);
                for (int i = 1; i <= 3; i++) {
                    gem(0, x - i, row);
                    deleteCell(cells, x - i, row);
                    points += 50;
                }
            }
            else if (count >= 4) {// Delete Four or more Consective Gems in a row and adding a flame gem
                hint(cells, true);
                bool flame_inserted = false;
                for (int i = 1; i <= count; i++) {
                    if (cells[x - i][row] < 6 && flame_inserted == false) {
                        gem(0, x - i, row);
                        cells[x - i][row] %= 6;
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

bool hint_row(int cells[cell_no][cell_no], int y) {
    bool hint_found = false;

    for (int x = 2; x < cell_no && hint_found == false; x++) {
        if (areGemsSame(cells[x][y], cells[x - 2][y]) == true) {
            if (areGemsSame(cells[x][y], cells[x - 1][y - 1]) == true && x >= 1 && y >= 1)
                hint_x = x - 1, hint_y = y - 1, hint_found = true;
            else if (areGemsSame(cells[x][y], cells[x - 1][y + 1]) == true && x >= 1 && y < cell_no - 1)
                hint_x = x - 1, hint_y = y + 1, hint_found = true;
        }
    }

    for (int x = 1; x < cell_no && hint_found == false; x++) {
        if (areGemsSame(cells[x][y], cells[x - 1][y]) == true) {
            if (areGemsSame(cells[x - 3][y], cells[x - 1][y]) == true && x >= 3) 
                hint_x = x - 3, hint_y = y, hint_found = true;
            else if (areGemsSame(cells[x - 2][y - 1], cells[x - 1][y]) == true && x >= 2 && y >= 1)
                hint_x = x - 2, hint_y = y - 1, hint_found = true;
            else if (areGemsSame(cells[x - 2][y + 1], cells[x - 1][y]) == true && x >= 2 && y < cell_no - 1)
                hint_x = x - 2, hint_y = y + 1, hint_found = true;
            else if (areGemsSame(cells[x + 2][y], cells[x][y]) == true && x < cell_no - 2)
                hint_x = x + 2, hint_y = y, hint_found = true;
            else if (areGemsSame(cells[x + 1][y - 1], cells[x][y]) == true && x < cell_no - 1 && y >= 1)
                hint_x = x + 1, hint_y = y - 1, hint_found = true;
            else if (areGemsSame(cells[x + 1][y + 1], cells[x][y]) == true && x >= 1 && y < cell_no - 1)
                hint_x = x + 1, hint_y = y + 1, hint_found = true;
        }
    }
    return hint_found;
}

bool hint_col(int cells[cell_no][cell_no], int x) {
    bool hint_found = false;
    for (int y = 1; y < cell_no && hint_found == false; y++) {
        if (areGemsSame(cells[x][y], cells[x][y - 1]) == true) {
            if (areGemsSame(cells[x][y - 3], cells[x][y - 1]) == true && y >= 3)
                hint_x = x, hint_y = y - 3, hint_found = true;
            else if (areGemsSame(cells[x - 1][y - 2], cells[x][y - 1]) == true && x >= 1 && y >= 2)
                hint_x = x - 1, hint_y = y - 2, hint_found = true;
            else if (areGemsSame(cells[x + 1][y - 2], cells[x][y - 1]) == true && x < cell_no - 1 && y >= 2)
                hint_x = x + 1, hint_y = y - 2, hint_found = true;
            else if (areGemsSame(cells[x][y + 2], cells[x][y]) == true && y < cell_no - 2)
                hint_x = x, hint_y = y + 2, hint_found = true;
            else if (areGemsSame(cells[x - 1][y + 1], cells[x][y]) == true && x >= 1 && y < cell_no - 1)
                hint_x = x - 1, hint_y = y + 1, hint_found = true;
            else if (areGemsSame(cells[x + 1][y + 1], cells[x][y]) == true && x < cell_no - 1 && y < cell_no - 1)
                hint_x = x + 1, hint_y = y + 1, hint_found = true;
        }
    }

    for (int y = 2; y < cell_no && hint_found == false; y++) {
        if (areGemsSame(cells[x][y], cells[x][y - 2]) == true) {
            if (areGemsSame(cells[x][y], cells[x - 1][y - 1]) == true && x >= 1 && y >= 1)
                hint_x = x - 1, hint_y = y - 1, hint_found = true;
            if (areGemsSame(cells[x][y], cells[x + 1][y - 1]) == true && x < cell_no - 1 && y >= 1)
                hint_x = x + 1, hint_y = y - 1, hint_found = true;
        }
    }
    return hint_found;
}

bool find_hint(int cells[cell_no][cell_no]){
    bool r = false, c = false;

    for (int row = 0; row < cell_no && r == false; row++)
        r = hint_row(cells, row);
    for (int col = 0; col < cell_no && c == false; col++)
        c = hint_col(cells, col);
    
    return (r || c);
}

bool hint(int cells[cell_no][cell_no], bool movement = false) {
    bool hint_found = false;
    if (movement == true) {
        int yellow_x = start_x + hint_x * (cell_size);
        int yellow_y = start_y + hint_y * (cell_size);
        myRect(yellow_x, yellow_y, yellow_x + cell_size, yellow_y + cell_size, 255, 255, 255);
        gem(cells[hint_x][hint_y], hint_x, hint_y);
        idle_tick = 0;
    }
    else {
        if (idle_tick >= 5) {
            hint_found = find_hint(cells);
            int yellow_x = start_x + hint_x * (cell_size);
            int yellow_y = start_y + hint_y * (cell_size);
            myRect(yellow_x, yellow_y, yellow_x + cell_size, yellow_y + cell_size, 0, 0, 255);
            gem(cells[hint_x][hint_y], hint_x, hint_y);
        }
    }
    return hint_found;
}

bool game(bool is_timed = true, bool point_based = false, int mins = 0, int secs = 0, int point_goal = 0, int str_points = 0) {
    myRect(50, 100, 1810, 880, 0, 0, 0);

    if (ext == true)
        return true;

    points = str_points;

    int keyboard_key;
    bool hint_found = false;
    bool key_pressed, is_selected = false, updated = false, time_out = false, goal_reached = false;
    int x = start_x, y = start_y, cell_x = 0, cell_y = 0, selected_x = -1, selected_y = -1;

    int cells[cell_no][cell_no] = {};

    randomizer(cells);
    DrawGems(cells);
    DrawGrid();
    myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
    DrawGems(cells);
    printPoints(points);

    if (point_based == true)
        printGoal(point_goal);

    if (is_timed == true)
        time_out = timer(mins, secs, updated, true);
    else
        stopwatch(mins, secs, updated, true);

    printTime(mins, secs);

    while (time_out == false) {
        updateCells(cells);

        if (is_timed == true)
            time_out = timer(mins, secs, updated);
        else
            stopwatch(mins, secs, updated);


        if (updated == true) {
            printPoints(points);
            hint_found = hint(cells, false);
            if (points >= point_goal && point_based == true) {
                time_out = true;
                goal_reached = true;
            }
        }

        key_pressed = isCursorKeyPressed(keyboard_key);


        if (key_pressed == true && keyboard_key == 1) {
            MoveSelectorLeft(x, y, cell_x, cell_y);
        }
        else if (key_pressed == true && keyboard_key == 2) {
            MoveSelectorUp(x, y, cell_x, cell_y);
        }
        else if (key_pressed == true && keyboard_key == 3) {
            MoveSelectorRight(x, y, cell_x, cell_y);
        }
        else if (key_pressed == true && keyboard_key == 4) {
            MoveSelectorDown(x, y, cell_x, cell_y);
        }
        else if (key_pressed == true && keyboard_key == 5) {
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected, true);
        }
        else if (key_pressed == true && keyboard_key == 6) {
            randomizer(cells);
        }
        else if (key_pressed == true && keyboard_key == 7) {
            pause_menu();
            if (ext == true)
                return false;
        }

        if (key_pressed == true) {
            DrawGrid();
            hint_found = hint(cells, false);
            selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
            myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
            DrawGems(cells);
            if (hint_found = false) {
                randomizer(cells);
                hint_found = hint(cells, false);
                selectionAndswapping(cells, cell_x, cell_y, selected_x, selected_y, is_selected);
                myRect(x, y, x + cell_size, y + cell_size, 255, 0, 0);
                DrawGems(cells);
            }
        }


    }
        
    game_over(point_based, mins, secs, points, goal_reached);

    key_pressed = isCursorKeyPressed(keyboard_key);
    while (!(key_pressed == true && keyboard_key == 7))
        key_pressed = isCursorKeyPressed(keyboard_key);

    if (point_based == true)
        return goal_reached;
    else
        menu();

    return false;
}

void menu_selection_color(int R[], int G[],int B[], const int option, int selection) {
    R[selection] = 9;
    G[selection] = 230;
    B[selection] = 31;

    for (int i = 0; i < option; i++)
        if (i != selection)
            R[i] = G[i] = B[i] = 255;
}

void print_option(char options[][10], int option, int R[], int G[], int B[]) {
    int men_str_y = 400, men_end_y = 470, men_str_x = 700, men_end_x = 1050;

    for (int i = 0; i < option; i++) {
        myRect(men_str_x, men_str_y + 100 * i, men_end_x, men_end_y + 100 * i, R[i], G[i], B[i]);
        drawText(24, men_str_x + 10, men_str_y + 10 + 100 * i, R[i], G[i], B[i], options[i]);
    }
}

int print_menu(const int option, char options[][10], char title[], int R[], int G[], int B[]) {

    myRect(50, 100, 1810, 880, 0, 0, 0);

    int corner_x = 1800;
    int corner_y = 870;

    int selection = 0;
    int men_str_y = 400, men_end_y = 470, men_str_x = 700, men_end_x = 1050;

    myRect(640, 240, 1110, 320, 30, 92, 250);
    drawText(30, 650, 250, 30, 92, 250, title);

    myLine(50, 100, corner_x, 100, 217, 30, 250);
    myLine(corner_x, 100, corner_x, corner_y, 217, 30, 250);
    myLine(corner_x, corner_y, 50, corner_y, 217, 30, 250);
    myLine(start_x, corner_y, 50, 100, 217, 30, 250);

    int keyboard_key;
    bool key_pressed = isCursorKeyPressed(keyboard_key);

    menu_selection_color(R, G, B, option, selection);

    print_option(options, option, R, G, B);

    while (!(key_pressed == true && keyboard_key == 5)) {
        key_pressed = isCursorKeyPressed(keyboard_key);

        if (key_pressed == true && keyboard_key == 2) {
            if (selection != 0)
                selection--;

        }

        else if (key_pressed == true && keyboard_key == 4) {
            if (selection != option - 1)
                selection++;
        }

        else if (key_pressed == true && keyboard_key == 7) {
            selection = option - 1;
                keyboard_key = 5;
        }
        menu_selection_color(R, G, B, option, selection);
        if (key_pressed == true) {
            myRect(640, 240, 1110, 320, 30, 92, 250);
            drawText(30, 650, 250, 30, 92, 250, title);

            myLine(start_x, start_y, corner_x, start_y, 217, 30, 250);
            myLine(corner_x, start_y, corner_x, corner_y, 217, 30, 250);
            myLine(corner_x, corner_y, start_x, corner_y, 217, 30, 250);
            myLine(start_x, corner_y, start_x, start_y, 217, 30, 250);

            print_option(options, option, R, G, B);
        }
    }
    
    
    return selection;
}

void pause_menu() {

    if (ext == true)
        return;

    char title[25] = "   Pause Menu";
    const int option = 2;
    char options[2][10] = { "Resume", "Exit"};
    int R[option], G[option], B[option];

    int selection = print_menu(option, options, title, R, G, B);

    if (selection == 0)
        myRect(50, 100, 1810, 880, 0, 0, 0);
    else if (selection == 1)
        menu();

    return;
}

void mode_menu() {

    if (ext == true)
        return;

    char title[25] = "  Game Modes";
    const int option = 4;
    char options[4][10] = { "Sandbox", "Challenge", "Timed", "Back"};
    int R[option], G[option], B[option];

    int selection = print_menu(option, options, title, R, G, B);

    if (selection == 0)
        game(false, false);
    else if (selection == 1) {
        int min_chal = 1, point_chal = 5000;
        bool challenge = game(true, true, min_chal, 0, point_chal);
        while (challenge == true) {
            min_chal += 1, point_chal += 5000;
            challenge = game(true, true, min_chal, 0, point_chal);
        }
    }

    else if (selection == 2)
        time_menu();
    else if (selection == 3)
        menu();

    menu();
}

void time_menu() {

    if (ext == true)
        return;

    char title[25] = "   Time Menu";
    const int option = 4;
    char options[4][10] = { "2 Minutes", "3 Minutes", "5 Minutes", "Back" };
    int R[option], G[option], B[option];

    int selection = print_menu(option, options, title, R, G, B);

    if (selection == 0)
        game(true, false, 2, 0);
    else if (selection == 1)
        game(true, false, 3, 0);
    else if (selection == 2)
        game(true, false, 5, 0);
    else if (selection == 3)
        mode_menu();
}

void menu() {

    if (ext == true)
        return;

    int corner_x = start_x + cell_size * 25;
    int corner_y = start_y + cell_size * 11;

    char title[25] = "Bejeweled Blitz";
    const int option = 2;
    char options[2][10] = { "Start", "Exit"};
    int R[option], G[option], B[option];

    int selection = print_menu(option, options, title, R, G, B);

    if (selection == 0)
        mode_menu();
    else if (selection == 1) {
        ext = true;
        return;
    }
}

int main() {

    if (ext == true)
        return 0;

    srand(time(0));

    system("@echo off");
    system("mode 800");

    //game(true, true, 5, 0, 10000);
    menu();
    return 0;
}