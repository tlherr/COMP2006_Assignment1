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
            FAHRENHEIT = 2,
            KELVIN = 3,
            ERROR_MARGIN = 5
        };

    protected:
        std::string name;
        int int_boiling_point_celsius;
        int int_boiling_point_kelvin;
        int int_boiling_point_fahrenheit;

    public:
        void setBoilingPoints (int celsius, int fahrenheit ,int kelvin) {
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
        bool isBoiling(int mode, int given_temp) {

            if(!int_boiling_point_celsius && !int_boiling_point_kelvin && !int_boiling_point_fahrenheit) {
                throw std::invalid_argument("Missing celcius, kelvin or fahrenheit temperature for material");
            }

            int temp;

            switch(mode) {
                case(BaseMaterial::CELSIUS):
                    temp = int_boiling_point_celsius;
                    break;
                case(BaseMaterial::KELVIN):
                    temp = int_boiling_point_kelvin;
                    break;
                case(BaseMaterial::FAHRENHEIT):
                    temp = int_boiling_point_fahrenheit;
                    break;
                default:
                    temp = int_boiling_point_celsius;
                    break;
            }

            //Calculation should be the following: make sure we know what temperature we are using
            //Determine if the given temperature is within +/- 5% (ERROR_MARGIN) of our boiling point
            //If it is return true, if not return false

            int temp_range = (temp * ERROR_MARGIN)/100;

            //We now have the range of 5% of that temp, find the absolute value of the difference
            int range_high = temp + temp_range;
            int range_low = temp - temp_range;

            std::printf("Comparing Material: %s Boiling Point: [%d] Error Margin: [%d] Range High: [%d] Range Low: [%d] \n", getDisplayName().c_str(), temp, temp_range, range_high, range_low);

            return given_temp >= range_low && given_temp <= range_high;
        };
};

#endif //COMP2006_ASSIGNMENT1_MATERIALS_H
