#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <limits>

int main() {
  int hrs =0;int mins =0;int secs=0;

    while (true) {
        // Clear line and print time
        std::cout << "\r"
                  << std::setw(2) << std::setfill('0') << hrs << ":"
                  << std::setw(2) << std::setfill('0') << mins << ":"
                  << std::setw(2) << std::setfill('0') << secs
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++secs;
            // Normalize input
    if (secs >= 60) {
        mins += secs / 60;
        secs %= 60;
    }
    if (mins >= 60) {
        hrs += mins / 60;
        mins %= 60;
    }
    //std::system("notify-send \"Your time: \" \"%i:%i:%i \"");
    }
//            std::cout << "\nTime's up!" << std::endl;


    return 0;
}

