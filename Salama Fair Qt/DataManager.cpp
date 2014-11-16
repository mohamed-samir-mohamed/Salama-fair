#include "DataManager.h"
#include "Item.h"

std::shared_ptr<DataManager> DataManager::mInstance = nullptr;

DataManager::DataManager()
{

}

DataManager::~DataManager()
{
    mItems.clear();
}

std::shared_ptr<DataManager> DataManager::getInstance()
{
    if (mInstance == nullptr)
        mInstance = std::shared_ptr<DataManager>(new DataManager());

    return mInstance;
}

void DataManager::addItem(std::shared_ptr<Item> fItem)
{
    if (mItems.find(fItem->getID()) != mItems.end())
    {
        //Item already exists.
    }

    mItems[fItem->getID()] = fItem;
}

std::shared_ptr<Item> DataManager::getItem(std::wstring fID) const
{
    if (mItems.find(fID) == mItems.end())
        return nullptr;

    return mItems.at(fID);
}

void DataManager::deleteItem(std::wstring fID)
{
    mItems.erase(fID);
}