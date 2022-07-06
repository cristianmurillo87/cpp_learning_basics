#include <iostream>

class Position
{
public:
    double x;
    double y;

    // Overload + operator
    // Defines the behavior of the + operator
    // e.g. position1 + position2
    Position operator+(Position other)
    {
        Position new_position;
        new_position.x = x + other.x;
        new_position.y = y + other.y;
        return new_position;
    }

    // Overload == operator
    bool operator==(Position other)
    {
        return x == other.x && y == other.y;
    }
};

int main()
{
    Position pos1, pos2;
    pos1.x = 10;
    pos1.y = 5;

    pos2.x = 12;
    pos2.y = 3;

    Position pos3 = pos1 + pos2;

    std::cout << "Position 1 X: " << pos1.x << " Y: " << pos1.y << std::endl;
    std::cout << "Position 2 X: " << pos2.x << " Y: " << pos2.y << std::endl;
    std::cout << "Position 3 X: " << pos3.x << " Y: " << pos3.y << std::endl;

    if (pos1 == pos2)
    {
        std::cout << "pos1 and pos2 are the same" << std::endl;
    }
    else
    {
        std::cout << "pos1 and pos2 are different" << std::endl;
    }

    return 0;
}