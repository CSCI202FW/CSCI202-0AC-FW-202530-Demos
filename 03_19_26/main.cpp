#include <iostream>
#include <string>
#include <limits>
#include "donut.h"

void referencePointers(donut *&, donut *);
void references(donut *&, donut &); // works the same as the one above
bool intInRange(int num, int low, int high);
int getInt(std::string prompt, std::string error, int low = 0, int high = 0, bool (*valid)(int, int, int) = intInRange);
bool gt0(int num, int low = 0, int high = 0);

void resetStream();

int main()
{
    donut *pointer1;
    donut myDonut;
    pointer1 = new donut("caramel", "Bacon", "Raspberry");
    referencePointers(pointer1, &myDonut);
    int numDonuts = getInt("How many donuts would you like? ", "That is not a valid number of donuts! Please enter a number between 1 and 12", 1, 12);
    donut **donuts;

    return 0;
};

void referencePointers(donut *&p, donut *d)
{
    d->setDrizzle("Peanut butter");
    donut *temp = p;
    p = d;
    d = temp;
}
void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

bool intInRange(int num, int low, int high)
{

    return num >= low && num <= high;
}

int getInt(std::string prompt, std::string error, int low, int high, bool (*valid)(int, int, int))
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    while (!std::cin || !valid(num, low, high))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << error << std::endl;
        std::cout << prompt;
        std::cin >> num;
    }

    return num;
}

bool gt0(int num, int low, int high)
{
    return num > 0;
}
