/**
 * Student Name: Thomas Herr
 * Student Number: 200325519
 * 17S Introduction to C++ - 01 (COMP2006-17S-30694)
 */

#include <iostream>
#include "Ass1-Boiling-ThomasHerr.h"

int main() {

    COMP2006_ASSIGNMENT1_ASS1_BOILING_THOMASHERR_H::question();

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
