//
// Created by Tom on 5/17/2017.
//

#ifndef COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H
#define COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H

#include <iostream>
#include <iomanip>

int get_lines() {
    int number;
    for(;;) {
        std::printf("Enter an integer number between 0 and 10 \n");

        if(std::cin >> number) {
            if(number < 0 || number > 10) {
                std::printf("Value must be between 1 and 10... \n");
                std::cin.clear();
                std::cin.ignore();
            } else {
                break;
            }
        } else {
            std::printf("Invalid Input Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    return number;
}

int factorial(int number) {
    if(number==0) {
        return 1;
    }

    return number * factorial(number -1);
}


void draw(int lines) {

    //Line
    int n = 0;
    //Row
    int k = 0;
    int left_padding = lines+1;

    //This loop runs once per line level (exponent number)
    for(n; n<=lines; n++) {
        //Set the inital padding
        std::cout << std::setw(left_padding);

        for(k=0; k<=n; k++) {
            //factorial(n)/(factorial(k)*factorial(n-k));
            //number of spaces in the row are equal to n
            int number = factorial(n)/(factorial(k)*factorial(n-k));
            std::cout << " " << number << " ";
        }


        left_padding--;
        std::cout << "\n";
    }
}

void question_three() {
    int lines = get_lines();
    draw(lines);
}



#endif //COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H
