

#include "donut.h"
#include <iostream>

int main()
{
    donut::toppingType t = donut::BACON;
    icingType i = CHOCOLATEICING;
    drizzleType d = drizzleType::CARAMELDRIZZLE;
    donut don("Maple", "Reeses Pieces", "Special");
    std::cout << don << std::endl;
    return 0;
}