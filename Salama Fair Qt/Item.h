#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item
{
public:
    Item();

    Item(wstring fID, wstring fTypeName, wstring fCompanyName, double fCashPrice);

    wstring getTypeName() const;
    double getPrice() const;
    wstring getCompanyName() const;
    wstring getID() const;

    void setID(long long fID);
    void setPrice(double fPrice);
    void setProviderName(string fName);
    void setTypeName(string fTypeName);

private:
    wstring mID;
    wstring mTypeName;
    wstring mProviderName;
    double mPrice;
};
#endif