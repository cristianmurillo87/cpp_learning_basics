#include <iostream>
#include <cmath>

#define PI 3.141519
#define AREA_CIRCLE(radius) (PI * pow(radius, 2))

int main()
{
    int r = 5;
    std::cout << "The area of a circle with radius " << r << " is: " << AREA_CIRCLE(r) << std::endl;
    return 0;
}