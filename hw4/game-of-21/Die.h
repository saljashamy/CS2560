// Specification file for the Die class
#ifndef DIE_H
#define DIE_H

class Die
{
private:
    int sides;
    int value;
    // Number of sides
    // The die's value
public:
    Die(int = 6);
    void roll();
    int getSides();
    int getValue();
};
#endif