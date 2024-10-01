#include <iostream>

using namespace std;

void displayPopulation(int year, double population) {
    cout << year << "\t" << population << endl;
}

int main() {
    int Year;
    double population[4];

    // Input year and population for each year
    cout << "Enter the year: ";
    cin >>Year;

    for (int i = 0; i < 4; ++i) {
        cout << "Enter population for year " << Year + i << ": ";
        cin >> population[i];
    }

    // Display population for four consecutive years
    cout << endl;
    cout << "Year\tPopulation" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < 4; ++i) {
        displayPopulation(Year + i, population[i]);
    }

    return 0;
}
