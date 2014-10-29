#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item
{
public:
    Item();

    Item(long long fID, string fTypeName, string fCompanyName, double fCashPrice);

    string getTypeName() const;
    double getPrice() const;
    string getCompanyName() const;
    long long getID() const;

    void setID(long long fID);
    void setPrice(double fPrice);
    void setProviderName(string fName);
    void setTypeName(string fTypeName);

private:
    long long mID;
    string mTypeName;
    string mProviderName;
    double mPrice;
};
#endif