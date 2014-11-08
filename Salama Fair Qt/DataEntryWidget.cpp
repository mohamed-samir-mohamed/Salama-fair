#include "DataEntryWidget.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <QCloseEvent>
#include "Item.h"

DataEntryWidget::DataEntryWidget(QWidget* parent , Qt::ItemFlags flags)
{
    mUi.setupUi(this);
}

DataEntryWidget::~DataEntryWidget()
{

}

void DataEntryWidget::on_actionEnter_triggered()
{
    if(mUi.IDLineEdit->text() == "")
    {
        QMessageBox msgBox(QString("معلومات مفقودة"), QString("من فضلك ادخل الرقم المسلسل"),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.show();
        return;
    }
    if(mUi.productNameLineEdit->toPlainText() == "")
    {
        QMessageBox msgBox(QString("معلومات مفقودة"), QString("من فضلك ادخل اسم المنتج"),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.show();
        return;
    }
    if(mUi.providerNameLineEdit->text() == "")
    {
        QMessageBox msgBox(QString("معلومات مفقودة"), QString("من فضلك ادخل اسم المورد"),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.show();
        return;
    }
    if(mUi.priceLineEdit->text() == "")
    {
        QMessageBox msgBox(QString("معلومات مفقودة"), QString("من فضلك ادخل سعر المنتج"),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.show();
        return;
    }  

    wstring id = mUi.IDLineEdit->text().toStdWString();
    wstring productName = mUi.productNameLineEdit->toPlainText().toStdWString();
    wstring providerName = mUi.providerNameLineEdit->text().toStdWString();
  
    double price = mUi.priceLineEdit->text().toDouble();
    auto item = shared_ptr<Item>(new Item(id,productName,providerName,price));

    mItems.push_back(item);
    //database save......
}

void DataEntryWidget::on_actionExit_triggered()
{
    mItems.clear();
    close();
}

void DataEntryWidget::closeEvent(QCloseEvent* fCloseEvent)
{
    QWidget::closeEvent(fCloseEvent);
    mItems.clear();
}

 std::vector<shared_ptr<Item>> DataEntryWidget::getItems() const
 {
     return mItems;
 }