#include "DataEntryDialog.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <QCloseEvent>
#include "Item.h"

DataEntryDialog::DataEntryDialog(QWidget* parent , Qt::ItemFlags flags)
{
    mUi.setupUi(this);
}

DataEntryDialog::~DataEntryDialog()
{

}

void DataEntryDialog::on_actionEnter_triggered()
{
    if(mUi.IDLineEdit->text() == "")
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"معلومات مفقودة")), QString(QString::fromStdWString(L"من فضلك ادخل الرقم المسلسل")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        return;
    }
    if(mUi.productNameLineEdit->toPlainText() == "")
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"معلومات مفقودة")), QString(QString::fromStdWString(L"من فضلك ادخل اسم المنتج")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        return;
    }
    if(mUi.providerNameLineEdit->text() == "")
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"معلومات مفقودة")), QString(QString::fromStdWString(L"من فضلك ادخل اسم المورد")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        return;
    }
    if(mUi.priceLineEdit->text() == "")
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"معلومات مفقودة")), QString(QString::fromStdWString(L"من فضلك ادخل سعر المنتج")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        return;
    }  
    //gather data from UI.
    std::wstring id = mUi.IDLineEdit->text().toStdWString();
    std::wstring productName = mUi.productNameLineEdit->toPlainText().toStdWString();
    std::wstring providerName = mUi.providerNameLineEdit->text().toStdWString();
  
    double price = mUi.priceLineEdit->text().toDouble();
    auto item = shared_ptr<Item>(new Item(id, productName, providerName, price));

    mItems.push_back(item);

    //message box
     QMessageBox msgBox(QString(QString::fromStdWString(L"عملية صحيحة")), QString(QString::fromStdWString(L"تم ")),QMessageBox::Warning,QMessageBox::Ok,0,0);
     msgBox.exec();

    //clear UI entries to allow new entries.
    mUi.IDLineEdit->clear();
    mUi.productNameLineEdit->clear();
    mUi.providerNameLineEdit->clear();
    mUi.priceLineEdit->clear();
}

void DataEntryDialog::on_actionExit_triggered()
{
    mItems.clear();
    close();
}

void DataEntryDialog::closeEvent(QCloseEvent* fCloseEvent)
{
    QWidget::closeEvent(fCloseEvent);
    mItems.clear();
}

 std::vector<shared_ptr<Item>> DataEntryDialog::getItems() const
{
     return mItems;
}