/**
 * According to projections US consumers put $51 billion in fast food charges on their credit and debit cards in 2006,
 * up from $33.2 billion in 2005.  Based on this model of the billions of fast food charges,
 *	F(t) = 33.2 + 16.8t
 * Where t is years since 2005, write a program that repeatedly prompts the user to enter a year after 2005 and
 * then predicts the billions of dollars of fast food charges US consumers will make in that year.
 * Tell the user that entry of a year before 2005 will cause the program to stop. Ensure you have an exit option
 * and error checking.
 */

#ifndef COMP2006_ASSIGNMENT1_ASSN1_TAKEAWAY_THOMASHERR_H
#define COMP2006_ASSIGNMENT1_ASSN1_TAKEAWAY_THOMASHERR_H

#include <iostream>

int get_year(){
    int year;
    for(;;) {
        std::printf("Enter a 4 digit year greater than 2005 (Program will exit if year is less than 2005): \n");

        if(std::cin >> year) {
            if(year < 2005) {
                std::printf("Year less than 2005, exiting program... \n");
                exit(0);
            }
            break;
        } else {
            std::printf("Invalid Integer Entered, expecting 4 digit integer greater than 2005. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }
    return year;
}

double calc_total(int year) {
    return 33.2 + 16.8 * (year - 2005);
}


void question_two() {
    int year = get_year();
    double spending = calc_total(year);

    std::printf("In the year: %d US spending on food is estimated to be: %f (Billion USD) \n", year, spending);
}



#endif //COMP2006_ASSIGNMENT1_ASSN1_TAKEAWAY_THOMASHERR_H
