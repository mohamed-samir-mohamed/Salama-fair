#include "Bill.h"

Bill::Bill() : mTotal(0.0)
{
    mItems = map<shared_ptr<Item>, int>();
}

void Bill::addItem(shared_ptr<Item> fItem, int fQuantity)
{
    mItems[fItem] = fQuantity;
}

 double Bill::getTotal()
{
     return mTotal;
}