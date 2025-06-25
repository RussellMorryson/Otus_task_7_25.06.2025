#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
//#include <Windows.h>

using namespace std;
 
void logging(std::chrono::duration<double> duration, string *info) { 
    string file_name = "log\\bulk" + to_string(duration.count()) + ".log";
    ofstream log_file(file_name);
    log_file << *info;
    log_file.close();
}

int main(int argc, char** argv) {
    int commands_limit = 3; // количество обрабатываемых команд до логгирования
    int count = 1; // счетчик до commands_limit
    string info = "bulk: "; // строка лога
    string com = "";
    bool com_block = false;

    if (argc > 1) {
        auto t0 = std::chrono::high_resolution_clock::now();
        for(int i = 1; i < argc; i++) {            
            //Sleep(1000);
            if (count == commands_limit) {
                info += argv[i];
                auto t1 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duration = t1 - t0;
                logging(duration, &info);
                info = "bulk: ";
                count = 1;
                auto t0 = std::chrono::high_resolution_clock::now();                
            } else if (i == argc-1) {
                info += argv[i];
                auto t1 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duration = t1 - t0;
                logging(duration, &info);                
            } else {
                info += argv[i];
                info += ", ";
                count +=1;                
            }
        }
    } else {
        std::cout << "You don't have parametrs";
        return 0;
    }
    cout << argc << endl;
    for(int i = 1; i < argc; i++) {
        cout << argv[i] << ' ';
    }    
    system("pause");
    return 0;
}
 
/*
0-main.exe
1-cmd1
2-cmd2
3-cmd3
Для продолжения нажмите любую клавишу . . .
*/