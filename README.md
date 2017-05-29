# Assignment 1 – Introduction to C++ and Decision Making

1. The table below shows the normal boiling points of several substances. Write a program that prompts the user for the observed oiling point of a substance in degrees C and identifies the substance if the observed boiling point is within 5% of the expected boiling point. If the data input is more than 5% higher or lower than any of the boiling points in the table, the program should output the message “substance unknown”
Substance	Normal Boiling Point (deg. C)
Water			100
Mercury		357
Copper			1187
Silver			2193
Gold			2660

2. Modify program 1 to allow the user to select between entry with Celsius, Fahrenheit, and Kelvin’s.  The logic of the application should remain the same and model the respective boiling points in the other unit bases. Use equations to determine the threshold of the various scales based on the normal boiling point in Celsius provided.
Save the source for number 2 as “Assn1-Boiling-YourName”

3. According to projections US consumers put $51 billion in fast food charges on their credit and debit cards in 2006, up from $33.2 billion in 2005.  Based on this model of the billions of fast food charges,
	F(t) = 33.2 + 16.8t
Where t is years since 2005, write a program that repeatedly prompts the user to enter a year after 2005 and then predicts the billions of dollars of fast food charges US consumers will make in that year.  Tell the user that entry of a year before 2005 will cause the program to stop. Ensure you have an exit option and error checking.

4. Write an application that will prompt the user for an exponent value input with a validity range of 0 to 10.  Using the entry create Pascal’s Triangle (with appropriate spacing) and display it on the screen.
This can be created by mimicking the table itself or through the modelling equation below.  The leading terms (ie. n(n-1)/2!) would be the number in Pascal`s triangle above.

5. Employ a switch structure to allow the user to select the application in Question 4 to draw Pascal`s Triangle or to proceed with the below:
Allow the user to enter a polynomial and use the binomial theorm to expand it.  A few notes:
	- Full expansion and simplification is not required
	- Limit the exponent to be a natural number only
	- It will only be binomial in that there are only 2 terms inside the brackets ie. (3x-24y)^7
- You can encapsulate the terms (x) and (y) while demonstrating in a textual interface the appropriate exponential function.  
- Thus you will have terms of:  (Term from Pascal’s Triangle)*(FirstTerm)^n*(SecondTerm)^k 
	- See below as an example:

Which is modelled by:
(A+B)^n=a^n+n*A^(n-1) B+(n(n-1))/2! A^(n-2) B^2+(n(n-1)(n-2))/3! A^(n-3) B^3+⋯+b^n
