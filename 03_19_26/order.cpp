#include "order.h"

Order::Order()
{
    donutList = nullptr;
    numDonuts = 0;
}

Order::Order(const Order &otherOrder)
{
    donutList = nullptr;
    numDonuts = 0;
    copyOrder(otherOrder);
}

const Order &Order::operator=(const Order &otherOrder)
{
    if (this != &otherOrder)
    {
        copyOrder(otherOrder);
    }
    return *this;
}

void Order::operator+(const donut &d)
{
    numDonuts++;
    if (donutList == nullptr)
    {
        donutList = new donut *[numDonuts];
    }
    else
    {
        donut **temp = donutList;
        donutList = new donut *[numDonuts];
        for (int i = 0; i < numDonuts - 1; i++)
        {
            donutList[i] = temp[i];
        }
        delete[] temp;
    }
    donutList[numDonuts - 1] = new donut(d);
}

Order::~Order()
{
    destroyList();
}

void Order::copyOrder(const Order &otherOrder)
{
    if (this->donutList != nullptr) //*(this).
    {
        destroyList();
    }
    this->numDonuts = otherOrder.numDonuts;
    this->donutList = new donut *[this->numDonuts];
    for (int i = 0; i < this->numDonuts; i++)
    {
        donutList[i] = new donut(*otherOrder.donutList[i]);
    }
}

void Order::destroyList()
{
    for (int i = 0; i < numDonuts; i++)
    {
        delete donutList[i];
        donutList[i] = nullptr;
    }
    delete[] donutList;
    donutList = nullptr;
}

std::ostream &operator<<(std::ostream &out, const Order &o)
{
    for (int i = 0; i < o.numDonuts; i++)
    {
        out << *o.donutList[i] << std::endl;
    }
    return out;
}
