#include "math_utils.h"

namespace matutils
{
    double area(double length, double width)
    {
        return length * width;
    }

    double area(double length)
    {
        return length * length;
    }

    double area(Rectangle rectangle)
    {
        return area(rectangle.length, rectangle.width);
    }

    double pow(double base, int pow)
    {
        double total = 1;
        for (int i = 0; i < pow; i++)
        {
            total *= base;
        }
        return total;
    }
}