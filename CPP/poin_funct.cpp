#include <iostream>
using namespace std;

void calcArea(const double* const pPi, // const pointer to const data
              const double* const pRadius, // nowt can be changed
              double* const pArea) // change pointed value, not the addy.
{
    if (pPi && pRadius && pArea)
        *pArea = (*pPi) * (*pRadius) * (*pRadius);

}

int main()
{
    const double Pi = 3.1416;

    cout << "Enter radius of circle: ";
    double Radius = 0;
    cin >> Radius;

    double Area = 0;
    calcArea(&Pi, &Radius, &Area);

    cout << "Area is = " << Area << endl;

    return 0;
}

