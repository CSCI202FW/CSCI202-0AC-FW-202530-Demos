#ifndef ORDER_H
#define ORDER_H
#include "donut.h"

class Order
{
public:
    Order();
    Order(const Order &);
    const Order &operator=(const Order &);
    void operator+(const donut &);
    friend std::ostream &operator<<(std::ostream &, const Order &);
    ~Order();

private:
    void copyOrder(const Order &);
    void destroyList();
    donut **donutList;
    int numDonuts;
};

#endif