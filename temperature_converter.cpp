#include <iostream>
#include <iomanip>
using namespace std;

double celsiusToFahrenheit(double c) { return (c * 9.0 / 5.0) + 32; }
double celsiusToKelvin(double c)     { return c + 273.15; }
double fahrenheitToCelsius(double f) { return (f - 32) * 5.0 / 9.0; }
double fahrenheitToKelvin(double f)  { return fahrenheitToCelsius(f) + 273.15; }
double kelvinToCelsius(double k)     { return k - 273.15; }
double kelvinToFahrenheit(double k)  { return celsiusToFahrenheit(kelvinToCelsius(k)); }

void convert(double value, char unit) {
    cout << fixed << setprecision(2);
    cout << "\nConverting: " << value << " ";

    if (unit == 'C' || unit == 'c') {
        cout << "Celsius\n";
        cout << "-> Fahrenheit : " << celsiusToFahrenheit(value) << " F\n";
        cout << "-> Kelvin     : " << celsiusToKelvin(value)     << " K\n";
    } else if (unit == 'F' || unit == 'f') {
        cout << "Fahrenheit\n";
        cout << "-> Celsius    : " << fahrenheitToCelsius(value) << " C\n";
        cout << "-> Kelvin     : " << fahrenheitToKelvin(value)  << " K\n";
    } else if (unit == 'K' || unit == 'k') {
        cout << "Kelvin\n";
        cout << "-> Celsius    : " << kelvinToCelsius(value)     << " C\n";
        cout << "-> Fahrenheit : " << kelvinToFahrenheit(value)  << " F\n";
    } else {
        cout << "Invalid unit! Use C, F or K\n";
    }
}

int main() {
    double value;
    char unit;
    char again = 'y';

    cout << "=== Temperature Converter ===\n";

    while (again == 'y' || again == 'Y') {
        cout << "\nEnter value and unit (C/F/K): ";
        cin >> value >> unit;
        convert(value, unit);

        cout << "\nConvert again? (y/n): ";
        cin >> again;
    }

    cout << "\nGoodbye!\n";
    return 0;
}