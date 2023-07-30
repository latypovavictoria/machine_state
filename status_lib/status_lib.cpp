#include <chrono>
#include <conio.h>
#include <iostream>
#include "status_lib.h"
#include <thread>

void State_1::increment_timer(char** argv) {
    status = std::cin.get();

    unsigned int tick = 22;
    while (timer_seconds < tick) {
        print_timer(timer_seconds);
        timer_seconds++;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    if (timer_seconds > 21 || 1 == status) {
        State_2 state2{ timer_seconds };
        state2.decrement_timer(argv);
    }
    else if (3 == status) {
        State_3 state3{ timer_seconds };
        state3.blinking_timer(argv);
    }
}

void State_2::decrement_timer(char** argv) {
    status = std::cin.get();

    while (timer_seconds > -2) {
        print_timer(timer_seconds);
        timer_seconds--;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    if (timer_seconds < 0 || 1 == status) {
        State_1 state1{ timer_seconds };
        state1.increment_timer(argv);
    }
    else if (3 == status) {
        State_3 state3{ timer_seconds };
        state3.blinking_timer(argv);
    }
}

void State_3::blinking_timer(char** argv) {
    status = std::cin.get();

    while (1 != status || 2 != status) {
        std::cout << "Stop";
        print_timer(timer_seconds);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main(int argc, char** argv) {

    if (argc <= 1) {
        return 0;
    }

    if (!strcmp(argv[1], "1")) {
        State_1 state1{ 0 };
        state1.status = 1;
        state1.increment_timer(argv);
    }

    else if (!strcmp(argv[1], "2")) {
        State_2 state2{ 0 };
        state2.status = 2;
        state2.decrement_timer(argv);
    }

    else if (!strcmp(argv[1], "3")) {
        State_3 state3{ 0 };
        state3.status = 3;
        state3.blinking_timer(argv);
    }
    
    else {
        return 0;
    }
}