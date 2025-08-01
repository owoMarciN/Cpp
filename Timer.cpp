#include <iostream>
#include <chrono>
#include <thread>

bool Quit = true;

std::string numbers[10][5] = {
        {" 0000 ", "0    0", "0    0", "0    0", " 0000 "},  // 0
        {"  11  ", "   1  ", "   1  ", "   1  ", " 11111"},  // 1
        {" 2222 ", "     2", " 2222 ", "2     ", "222222"},  // 2
        {" 3333 ", "     3", "  333 ", "     3", " 3333 "},  // 3
        {"4    4", "4    4", " 44444", "     4", "     4"},  // 4
        {"555555", "5     ", "555555", "     5", "555555"},  // 5
        {" 6666 ", "6     ", "666666", "6    6", " 6666 "},  // 6
        {"777777", "     7", "    7 ", "   7  ", "  7   "},  // 7
        {" 8888 ", "8    8", " 8888 ", "8    8", " 8888 "},  // 8
        {" 9999 ", "9    9", " 99999", "     9", " 9999 "}   // 9
};

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printTimer(std::string number){
    for(int row = 0; row < 5; row++){
        for(char c : number){
            switch(c){
                case ':': std::cout << "   :   "; break;
                case '.': std::cout << "   .   "; break;
                default: std::cout << numbers[c - '0'][row] << "  "; break;
            }
        }
        std::cout << '\n';
    }
}

void Print(int hh, int mm, int ss, int ms) {
    clearScreen();

    std::string hours = (hh < 10 ? "0" : "") + std::to_string(hh);
    std::string minutes = (mm < 10 ? "0" : "") + std::to_string(mm);
    std::string seconds = (ss < 10 ? "0" : "") + std::to_string(ss);
    std::string milliseconds = (ms < 10 ? "0" : "") + std::to_string(ms);

    std::cout << '\n';
    printTimer(hours + ":" + minutes + ":" + seconds + "." + milliseconds);
}

void EnterKey(){
    std::cin.get();
    Quit = false;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    std::thread Thread(EnterKey);

    while(Quit){
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);

        int hours = std::chrono::duration_cast<std::chrono::hours>(duration).count();
        int minutes = std::chrono::duration_cast<std::chrono::minutes>(duration).count() % 60;
        int seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count() % 60;
        int milliseconds = duration.count() % 100;

        std::cout << "\rTime format -- [ hh:mm:ss.ms ] -- click \"Enter\" to stop!";
        std::cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":";
        std::cout << (seconds < 10 ? "0" : "") << seconds << "." << (milliseconds < 10 ? "0" : "") << milliseconds;

        Print(hours, minutes, seconds, milliseconds);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    Thread.join();

    return 0;
}

