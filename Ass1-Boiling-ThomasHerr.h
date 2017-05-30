/**
 * Write a program that prompts the user for the observed oiling point of a substance in degrees C and identifies the
 * substance if the observed boiling point is within 5% of the expected boiling point
 */

#ifndef COMP2006_ASSIGNMENT1_ASS1_BOILING_THOMASHERR_H
#define COMP2006_ASSIGNMENT1_ASS1_BOILING_THOMASHERR_H

#include <iostream>
#include <limits>
#include "Materials.h"
#include "Temperature.h"

BaseMaterial substances[5];

/**
 * Show user options and request they select an option
 * @return Integer type selected
 */
int get_units() {

    int type;

    for (;;) {
        std::printf("Enter a unit type to be used: \n");
        std::printf("1 - Celsius \n");
        std::printf("2 - Fahrenheit \n");
        std::printf("3 - Kelvin \n");

        std::cin >> type;

        if(!std::cin.fail()) {
            if(type==1||type==2||type==3) {
                std::printf("Using Type: %d \n", type);
                break;
            } else {
                std::printf("Invalid input provided, please enter an integer from the above list \n");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

        } else {
            std::printf("Invalid input provided, please enter an integer from the above list \n");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return type;
}

/**
 * Ask the user for an integer number temperature
 * @return Integer temperature provided
 */
int get_temp() {
    int temp;

    for(;;) {
        std::printf("Enter an integer temperature: \n");

        std::cin >> temp;

        if(!std::cin.fail()) {
            break;
        } else {
            std::printf("Invalid Integer Entered, please try again \n");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return temp;
}

/**
 * Check substances to find a matching temp
 * @param temp
 */
void check_substances(int mode, int temp) {
    bool match = false;
    int index = 0;

    for(int i=0; i < 4 ; i++) {
        if(substances[i].isBoiling(mode, temp)) {
            match = true;
            index = i;
        }
    }

    if(match) {
        std::printf("Substance is: %s \n", substances[index].getDisplayName().c_str());
    } else {
        std::printf("No Match Found. Unknown substance \n");
    }
}

/**
 * Ask user what they would like to do, if a valid selection run that option
 */
void question_one() {
    BaseMaterial water;
    BaseMaterial mercury;
    BaseMaterial copper;
    BaseMaterial silver;
    BaseMaterial gold;

    //Set initial values
    water.setBoilingPoints(100, toFahrenheit(100), toKelvin(100));
    water.setDisplayName("Water");
    mercury.setBoilingPoints(357, toFahrenheit(357), toKelvin(357));
    mercury.setDisplayName("Mercury");
    copper.setBoilingPoints(1187, toFahrenheit(1187), toKelvin(1187));
    copper.setDisplayName("Copper");
    silver.setBoilingPoints(2193, toFahrenheit(2193), toKelvin(2193));
    silver.setDisplayName("Silver");
    gold.setBoilingPoints(2660, toFahrenheit(2660), toKelvin(2660));
    gold.setDisplayName("Gold");

    substances[0] = water;
    substances[1] = mercury;
    substances[2] = copper;
    substances[3] = silver;
    substances[4] = gold;

    //Steps: Prompt for units, prompt for temp, check values, display result, ask to continue
    int unit_type = get_units();
    int temp = get_temp();
    check_substances(unit_type, temp);
}



#endif //COMP2006_ASSIGNMENT1_ASS1_BOILING_THOMASHERR_H
