#include "InqueryDialog.h"
#include "DataManager.h"
#include "Item.h"
#include <qmessagebox.h>

InqueryDialog::InqueryDialog(QWidget* parent/* = nullptr*/, Qt::ItemFlags flags /*= 0*/):QDialog(parent)
{
    mUi.setupUi(this);

    enableEditMode(false);
}

InqueryDialog::~InqueryDialog()
{

}

void InqueryDialog::on_actionEdit_triggered()
{
    if (inquery())
        enableEditMode(true);
}

void InqueryDialog::on_actionInquery_triggered()
{
    inquery();
}

void InqueryDialog::on_actionBack_triggered()
{
    accept();
    clearTexts();
}

void InqueryDialog::on_actionDelete_triggered()
{
    if (inquery() == false)
        return;

    /////////////////////////////////////////////////////////////////////////////////
    QMessageBox msgBox;
    msgBox.setWindowTitle(QString::fromStdWString(L"تأكيد مسح السلعة"));
    msgBox.setInformativeText(QString::fromStdWString(L"هل تريد مسح هذة السلعة ؟"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Yes)
    {
        std::wstring id = mUi.IDlineEdit->text().toStdWString();
        DataManager::getInstance()->deleteItem(id);
        clearTexts();
    }
}

void InqueryDialog::clearTexts()
{
    mUi.productNameTextEdit->setText("");
    mUi.ProviderNameLineEdit->setText("");
    mUi.priceLineEdit->setText("");
    mUi.IDlineEdit->setText("");
}

void InqueryDialog::enableTexts(bool fEnable)
{
    mUi.priceLineEdit->setEnabled(fEnable);
    mUi.productNameTextEdit->setEnabled(fEnable);
    mUi.ProviderNameLineEdit->setEnabled(fEnable);
}

void InqueryDialog::enableEditMode(bool fEnable)
{
    mUi.editApproveButton->setHidden(!fEnable);
    mUi.deleteButton->setEnabled(!fEnable);
    mUi.editButton->setEnabled(!fEnable); 
    mUi.inqueryButton->setEnabled(!fEnable);
    mUi.IDlineEdit->setEnabled(!fEnable);
    enableTexts(fEnable);
}

void InqueryDialog::on_actionApproveEdit_triggered()
{
    wstring id = mUi.IDlineEdit->text().toStdWString();
    auto item = DataManager::getInstance()->getItem(id);
    double price = mUi.priceLineEdit->text().toDouble();

    item->setTypeName(mUi.productNameTextEdit->toPlainText().toStdWString());
    item->setProviderName(mUi.ProviderNameLineEdit->text().toStdWString());
    item->setPrice(price);

    enableEditMode(false); 
}

bool InqueryDialog::inquery()
{
    std::wstring itemID = mUi.IDlineEdit->text().toStdWString();

    if (itemID == L"")
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"بيانات")), QString(QString::fromStdWString(L"من فضلك ادخل كود السلعة")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        clearTexts();
        return false;

    }

    auto item = DataManager::getInstance()->getItem(itemID);

    if (item == nullptr)
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"بيانات")), QString(QString::fromStdWString(L"لا يوجد سلعة بهذا الكود")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        clearTexts();
        return false;
    }

    mUi.productNameTextEdit->setText(QString::fromStdWString(item->getTypeName()));
    mUi.ProviderNameLineEdit->setText(QString::fromStdWString(item->getCompanyName()));
    mUi.priceLineEdit->setText(QString::number(item->getPrice()));
    return true;
}
