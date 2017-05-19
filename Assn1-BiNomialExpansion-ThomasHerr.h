//
// Created by Tom on 5/17/2017.
//

#ifndef COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H
#define COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H

#include <iostream>
#include <iomanip>
#include <regex>
#include <vector>

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


void draw_pascal(int lines) {

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
            std::cout << " " << number;
        }

        left_padding--;
        std::cout << "\n";
    }
}

std::string get_polynomial() {
    return "(3x-24y)^7";
}

/**
 * (a+b)^n = the sum from k=0 to n of (n choose k) * a^(n-k) * b^k
 *
 * Example: (3x-24y)^7
 *
 */
void binomial_theorem(std::string expression) {
    int n;
    int k = 0;
    int a;
    int b;

    std::vector<std::string> terms;

    //Get the power being raised from the expression
    std::cmatch end_exponent_match;
    if(std::regex_search(expression.c_str(), end_exponent_match, std::regex("([)][\\\\^][0-9])"))) {
        n = expression[end_exponent_match.prefix().length()+2];
    } else {
        n = 1;
    }

    //Get the terms
    //(([0-9][a-z])|[0-9]+)
    std::cmatch term_match;
    while(std::regex_search(expression.c_str(), term_match, std::regex("(([0-9][a-z])|[0-9]+)"))) {
        //Getting terms, expecting any number letter or just number combinations
        terms.push_back(term_match.str());
    }

    for(int i =)
}


void generate_pascal(int lines, std::string expression) {
    int n = 0;
    int k = 0;

    for(n; n<=lines; n++) {
        for (k = 0; k <= n; k++) {
            int number = factorial(n) / (factorial(k) * factorial(n - k));
        }

        std::cout << "\n";
    }

}


void question_three() {
//    int option;
//    for (;;) {
//        std::printf("Select Option: \n");
//        std::printf("1) Draw Triangle \n");
//        std::printf("2) Enter Polynomial \n");
//
//        if(std::cin >> option) {
//            if(option==1|option==2) {
//                std::printf("Option %d selected \n", option);
//                break;
//            } else {
//                std::printf("Invalid input provided, please enter an integer from the above list \n");
//                std::cin.clear();
//                std::cin.ignore();
//            }
//        } else {
//            std::printf("Invalid input provided, please try again \n");
//            std::cin.clear();
//            std::cin.ignore();
//        }
//    }
//
//    int lines = get_lines();
//
//    switch(option) {
//        case 1:
//            draw_pascal(lines);
//            break;
//        case 2:
//            std::string polynomial = get_polynomial();
//            generate_pascal(lines, polynomial);
//            break;
//    }

    binomial_theorem("3x-24y)^7");
}



#endif //COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H