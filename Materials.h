//
// Created by Thomas Herr on 2017-05-15.
//

#include <stdexcept>
#include <string>

#ifndef COMP2006_ASSIGNMENT1_MATERIALS_H
#define COMP2006_ASSIGNMENT1_MATERIALS_H

class BaseMaterial {

    public:
        enum Constants {
            CELSIUS = 1,
            KELVIN = 2,
            FAHRENHEIT = 3,
            ERROR_MARGIN = 5
        };

    protected:
        std::string name;
        int int_boiling_point_celsius;
        int int_boiling_point_kelvin;
        int int_boiling_point_fahrenheit;

    public:
        void setBoilingPoints (int celsius, int kelvin ,int fahrenheit) {
            int_boiling_point_celsius = celsius;
            int_boiling_point_fahrenheit = fahrenheit;
            int_boiling_point_kelvin = kelvin;
        }
        void setDisplayName(std::string n) {
            name = n;
        }
        std::string getDisplayName() {
            return name;
        }
        bool isBoiling(int mode, int temp) {

            if(!int_boiling_point_celsius && !int_boiling_point_kelvin && !int_boiling_point_fahrenheit) {
                throw std::invalid_argument("Missing celcius, kelvin or fahrenheit");
            }

            int difference = 0;

            switch(mode) {
                case(BaseMaterial::CELSIUS):
                    difference = int_boiling_point_celsius - temp;
                    break;
                case(BaseMaterial::KELVIN):
                    difference = int_boiling_point_kelvin - temp;
                    break;
                case(BaseMaterial::FAHRENHEIT):
                    difference = int_boiling_point_fahrenheit - temp;
                    break;
            }

            std::printf("Temp: %d Difference: %d Percentage: %d \n", temp, difference, (temp * ERROR_MARGIN));


            //If there is more than a 5% difference return false
            return ((temp * ERROR_MARGIN) / 100) < abs(difference);

        };
};

#endif //COMP2006_ASSIGNMENT1_MATERIALS_H
