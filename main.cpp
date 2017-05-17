/**
 * Student Name: Thomas Herr
 * Student Number: 200325519
 * 17S Introduction to C++ - 01 (COMP2006-17S-30694)
 */

#include <iostream>
#include "Ass1-Boiling-ThomasHerr.h"
#include "Assn1-TakeAway-ThomasHerr.h"

int main() {

    int question;

    std::printf("COMP2006 Assignment 1 Menu \n");
    std::printf("=========Questions=========\n");
    std::printf("1) Substance Boiling Point Calculator \n");
    std::printf("2) Fast Food Spending Calculator \n");

    for(;;) {
        std::printf("Select a question to run: \n");

        if(std::cin >> question) {
            break;
        } else {
            std::printf("Invalid Integer Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    switch(question) {
        default:
            std::printf("No question selected, exiting \n");
            return 0;
        case 1:
            COMP2006_ASSIGNMENT1_ASS1_BOILING_THOMASHERR_H::question_one();
            break;
        case 2:
            COMP2006_ASSIGNMENT1_ASSN1_TAKEAWAY_THOMASHERR_H::question_two();
            break;
    }

    #if defined(__linux__)
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
    #elif defined(__APPLE__)
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
    #elif defined(_WIN32)
        system("pause");
    #elif defined(_WIN64)
        system("pause");
    #endif

    return 0;
}
