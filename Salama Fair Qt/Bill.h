#ifndef BILL_H
#define BILL_H
using namespace std;


#include "Item.h"
#include <memory>
#include<map>

#include <QDate>

class Bill
{
public:

    Bill();
    void addItem(shared_ptr<Item> fItem, int fQuantity = 1);
    double getTotal();

private:
    map<shared_ptr<Item>, int>  mItems; //ID - Quantity.
    double mTotal;
    QDate mDate;
};
#endif