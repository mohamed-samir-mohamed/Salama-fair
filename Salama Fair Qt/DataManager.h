#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <map>
#include <memory>
#include <string>

class Item;

class DataManager
{

public:
    static std::shared_ptr<DataManager> getInstance();
    ~DataManager();

    void addItem(std::shared_ptr<Item> fItem);
    void deleteItem(std::wstring fID);
    std::shared_ptr<Item> getItem(std::wstring fID) const ;

private:
    DataManager();
    std::map<std::wstring ,std::shared_ptr<Item>> mItems;

    static std::shared_ptr<DataManager> mInstance;
};
#endif