//
// Created by Thomas Herr on 2017-05-15.
//

#ifndef COMP2006_ASSIGNMENT1_TEMPERATURE_H
#define COMP2006_ASSIGNMENT1_TEMPERATURE_H


//To convert temperatures in degrees Celsius to Fahrenheit, multiply by 1.8 (or 9/5) and add 32.
int toFahrenheit(int c_temp) {
    return (c_temp * 9/5) + 32;
}

//The temperature T in Kelvin (K) is equal to the temperature T in degrees Celsius (°C) plus 273.15
int toKelvin(int c_temp) {
    return (int) (c_temp + 273.15);
}

#endif //COMP2006_ASSIGNMENT1_TEMPERATURE_H
