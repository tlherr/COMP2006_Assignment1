//
// Created by Tom on 5/17/2017.
//

#ifndef COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H
#define COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H

#include <iostream>
#include <iomanip>
#include <regex>
#include <vector>

/**
 * Get user input, validate it is an integer in reuqested range (0-10)
 * Ask for another entry if current is invalid
 * @return Integer Number of lines of triangle to generate
 */
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

/**
 * Recursive factorial function, decrease multiplier on each iteration
 * @param Integer Number to calculate factorial of
 * @return current factorial or final result depending on number
 */
int factorial(int number) {
    if(number <= 1) return 1;

    return number * factorial(number - 1);
}

/**
 * Draw pascals triangle based on user input
 */
void draw_pascal() {

    int lines = get_lines();

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
            int number = factorial(n)/(factorial(k)*factorial(n-k));
            std::cout << " " << number;
        }

        left_padding--;
        std::cout << "\n";
    }
}

/**
 * Validate a given term, looking for any number of digits followed by a single character between a to z
 * @param expression String User Input
 * @return Boolean is term valid or should we discard it and ask user for another
 */
bool validate_term(std::string expression) {
    return (std::regex_search(expression, std::regex("^[0-9]+[a-z]{1}$")));
}
/**
 * Input loop asking and validating a term
 * @return String term
 */
std::string get_term() {
    std::string term;
    for(;;) {
        if(std::cin >> term) {
            if(!validate_term(term)) {
                std::printf("Input did not match expected pattern \n");
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

    return term;
}

/**
 * Validate user input to ensure they provided a valid arithmetic operator
 * @param op Char user input character
 * @return Boolean if operator provided is valid
 */
bool validate_op(char op) {
    return op == '+' || op == '-' || op == '/' || op == '*';

}
/**
 * Input loop asking for an arithmetic operator and validating input
 * @return Char operator provided by user
 */
char get_operator() {
    char op;
    for(;;) {
        std::printf("Enter an operator Allowed: + - / * \n");

        if(std::cin >> op) {
            if(!validate_op(op)) {
                std::printf("Input did not match expected pattern \n");
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

    return op;
}

/**
 * Function to use binomial theorem to expand a binomial
 * @ref: http://www.purplemath.com/modules/binomial2.htm
 * (a+b)^n = the sum from k=0 to n of (n choose k) * a^(n-k) * b^k
 */
void binomial_theorem() {

    //Get first term
    std::printf("Enter first term (Example: 3x) \n");
    std::string term1 = get_term();
    //Get operator
    char op = get_operator();
    //Get second term
    std::printf("Enter second term (Example: 3x) \n");
    std::string term2 = get_term();
    //Get Power
    std::printf("Enter a power: ");
    int n = get_lines();

    int k = 0;

    //(n choose k) * a^(n-k) * b^k
    for(int i = n; i >= 0; i--) {
        for(k; k <= n; k++) {
            int n_choose_k = factorial(n) / (factorial(k) * factorial(n - k));
            std::cout << n_choose_k << "(" << term1 << ")^" << n << "-" << k << " *" << op << term2 << "^" << k << " + ";
        }
    }

}

/**
 * Ask user what they would like to do, if a valid selection run that option
 */
void question_three() {
    int option;
    for (;;) {
        std::printf("Select Option: \n");
        std::printf("1) Draw Triangle \n");
        std::printf("2) Enter Polynomial \n");

        if(std::cin >> option) {
            if(option==1|option==2) {
                std::printf("Option %d selected \n", option);
                break;
            } else {
                std::printf("Invalid input provided, please enter an integer from the above list \n");
                std::cin.clear();
                std::cin.ignore();
            }
        } else {
            std::printf("Invalid input provided, please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    switch(option) {
        case 1:
            draw_pascal();
            break;
        case 2:
            binomial_theorem();
            break;
        default:
            std::cout << "Invalid Option Provided, Exiting...";
            break;
    }

}



#endif //COMP2006_ASSIGNMENT1_ASSN1_BINOMIALEXPANSION_THOMASHERR_H
