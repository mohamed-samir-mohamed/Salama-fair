#include "Item.h"

Item::Item(): mPrice(0.0), mTypeName(""), mProviderName(""), mID(-1)
{

}

Item::Item(wstring fID, wstring fTypeName, wstring fCompanyName, double fCashPrice) :
    mPrice(fCashPrice), 
    mTypeName(fTypeName),
    mProviderName(fCompanyName),
    mID(fID)
{

}

wstring Item::getTypeName() const
{
    return mTypeName;
}

double Item::getPrice() const
{
    return mPrice;
}

wstring Item::getCompanyName() const
{
    return mProviderName;
}

wstring Item::getID() const
{
    return mID;
}

void Item::setID(long long fID)
{
    mID = fID;
}

void Item::setPrice(double fCashPrice)
{
    mPrice = fCashPrice;
}

void Item::setProviderName(string fName)
{
    mProviderName = fName;
}

void Item::setTypeName(string fTypeName)
{
    mTypeName = fTypeName;
}