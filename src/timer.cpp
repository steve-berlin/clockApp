#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>

int main() {
    int hrs = 0, mins = 0, secs = 0;
    int sfx=1;
    std::cout << "choose sound effect: ";
    std::cin >> sfx;
    std::cout << "hours: ";
    std::cin >> hrs;
    if (!std::cin || hrs < 0) {
        std::cerr << "Not a valid input for hours\n";
        return 1;
    }

    std::cout << "minutes: ";
    std::cin >> mins;
    // Check for input failure or negative minutes
    if (!std::cin || mins < 0) {
        std::cerr << "Not a valid input for minutes\n";
        return 1;
    }

    // Optionally, prompt for seconds
    std::cout << "seconds: ";
    std::cin >> secs;
    if (!std::cin || secs < 0) {
        std::cerr << "Not a valid input for seconds\n";
        return 1;
    }
    // Normalize input
    if (secs >= 60) {
        mins += secs / 60;
        secs %= 60;
    }
    if (mins >= 60) {
        hrs += mins / 60;
        mins %= 60;
    }
if (sfx < 1 || sfx > 5) {
        std::cerr << "Invalid sound effect choice. Please choose between 1 and 3.\n";
        return 1;
  
} else
    int total_seconds = hrs * 3600 + mins * 60 + secs;

    while (total_seconds > 0) {
        int display_hrs = total_seconds / 3600;
        int display_mins = (total_seconds % 3600) / 60;
        int display_secs = total_seconds % 60;

        // Clear line and print time
        std::cout << "\r"
                  << std::setw(2) << std::setfill('0') << display_hrs << ":"
                  << std::setw(2) << std::setfill('0') << display_mins << ":"
                  << std::setw(2) << std::setfill('0') << display_secs
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        --total_seconds;
    }

    int fd = open("/dev/input/event0", O_RDONLY);
    input_event ev;
         std::system("notify-send \"Time's up!\" \"The timer has finished counting down!\"");
   /* while (true){
    while (read(fd, &ev, sizeof(ev)) > 0){*/
std::string command = "mpv src/sfx/" + std::to_string(sfx) + ".mp3";
std::system(command.c_str());
   /*   if (ev.code == 16 && ev.value == 1){
        std::exit(0);
      }

    }
    }*/
    //std::cout << "\nTime's up!" << std::endl;
 }
 //   return 0;


