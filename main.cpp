/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *       Name: 07-Arrays-intro                                             *
 *                                                                         *
 *       Purpose:                                                          *
 *       Receives 10 integers provided by the user from the console,       *
 *       and stores them in an array. And then based on them, it           *
 *       calculates the sum, the average and the largest element.          *
 *                                                                         *
 *       More Details:                                                     *
 *                                          *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::string;
using std::to_string;
using std::stringstream;

// Receives and validates an integer number from the console
int getInteger(const string &, int minValue, int maxValue);

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(unsigned long long int);

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(long double, int = 2);

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfElements(const int [], int);

// Calculates the average among all the numbers inside an array of integers
double averageAmongIntegers(const int [], int);

// Determines the highest number among an array of integers
int highestInteger(const int [], int);

// Main Function
int main() {
    constexpr int SIZE = 10; // The size of the array
    int integersArray[SIZE]; // The array of integers

    // Looping to fill the array with the integer numbers provided by the user
    for (int &item: integersArray) {
        item = getInteger("Please type a number", 0, INT_MAX);
    }

    int sum = 0; // The sum of all the numbers inside the array of integers
    double average = 0.0; // The average of all the numbers inside the array of integers
    int highestElement = 0; // The highest number inside the array of integers

    sum = simpleSumOfElements(integersArray, SIZE);
    average = averageAmongIntegers(integersArray, SIZE);
    highestElement = highestInteger(integersArray, SIZE);

    // Printing the results on the console
    cout << "" << endl;
    cout << "The sum of the elements is " << humanizeUnsignedInteger(sum) << endl;
    cout << "The average is " << humanizeUnsignedDouble(average) << endl;
    cout << "The highest element is " << humanizeUnsignedInteger(highestElement) << endl;

    return 0;
}

// Receives and validates an integer number from the console
int getInteger(const string &message, const int minValue, const int maxValue) {
    int number = 0;
    bool invalidInput;

    do {
        cout << message << " (" << minValue << " - " << maxValue << "): ";
        cin >> number;
        cin.ignore();

        invalidInput = number < minValue || maxValue < number;
        if (invalidInput) cout << "Invalid input. Please try again." << endl;
    } while (invalidInput);

    return number;
}

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(const unsigned long long int integerValue) {
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > 0; j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<unsigned long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanizeUnsignedInteger(integerValue) + decimalsAsString.substr(1, precision + 1);
}

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfElements(const int integersArray[], const int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += integersArray[i];
    }

    return sum;
}


// Calculates the average among all the numbers inside an array of integers
double averageAmongIntegers(const int array[], const int length) {
    return simpleSumOfElements(array, length) / static_cast<double>(length);
}

// Determines the highest number among an array of integers
int highestInteger(const int integersArray[], const int length) {
    int highestInteger = integersArray[0];
    if (length == 1) return highestInteger;

    for (int i = 1; i < length; i++) {
        if (integersArray[i] > highestInteger)
            highestInteger = integersArray[i];
    }

    return highestInteger;
};
