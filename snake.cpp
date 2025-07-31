#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <windows.h>

void clear_screen() {
#ifdef _WIN32
    //std::system("cls");

    //SETTING CONSOLE CURSOR TO REDUCE "FLICKERING"
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    //SETTING CONSOLE CURSOR VISIBILITY
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
#else
    std::system("clear");
#endif
}

bool gameOver;

const int width = 20;
const int height = 17;

int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100];
int nTail;

enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN} dir;

void setup() {
#ifdef _WIN32
    std::system("cls");
#endif
    gameOver = false;

    dir = STOP;

    x = width / 2;
    y = height / 2;

    fruitX = rand() % width;
    fruitY = rand() % height;

    score = 0;
}

void draw() {
    clear_screen();

    for (int i = 0; i < width+2; i++) std::cout << "#";
    std::cout << std::endl;
        
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) std::cout << "#";
            if (i == y && j == x) std::cout << "*";
            else if (i == fruitY && j == fruitX) std::cout << "%";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        std::cout << "*";
                        print = true;
                    }
                }
                if (!print) std::cout << " ";
            }
            if (j == width - 1) std::cout << "#"; 
        }
        std::cout << std::endl;
    }

     for (int i = 0; i< width+2; i++) {
        std::cout << "#";
    }

    std::cout << std::endl;
    std::cout << "Score:" << score << std::endl;
    std::cout << "Click \"x\" to exit!" << std::endl; 
}

void input() {
    if (_kbhit()) {
        switch(_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

void algorithm() {
    int prevX = tailX [0];
    int prevY = tailY [0];

    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for(int i = 1; i < nTail; i++) {

        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;  
        default: break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width-1;

    if (y >= height) y = 0; else if (y < 0) y = height-1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main(int argc, const char * argv[]) {
    setup();
    while (!gameOver) {
        draw();
        input();
        algorithm();
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
    
    return 0;
}