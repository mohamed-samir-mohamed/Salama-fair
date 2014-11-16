#include "InqueryDialog.h"
#include "DataManager.h"
#include "Item.h"
#include <qmessagebox.h>

InqueryDialog::InqueryDialog(QWidget* parent/* = nullptr*/, Qt::ItemFlags flags /*= 0*/):QDialog(parent)
{
    mUi.setupUi(this);

    enableTexts(false);
}

InqueryDialog::~InqueryDialog()
{

}

void InqueryDialog::on_actionEdit_triggered()
{
    std::wstring id = mUi.IDlineEdit->text().toStdWString();
    if (id == L"")
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"معلومات مفقودة")), QString(QString::fromStdWString(L"من فضلك ادخل كود السلعة")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        return;
    }

    //enableTexts();
}

void InqueryDialog::on_actionInquery_triggered()
{
    std::wstring itemID = mUi.IDlineEdit->text().toStdWString();
    auto item = DataManager::getInstance()->getItem(itemID);

    if (item == nullptr)
    {
        QMessageBox msgBox(QString(QString::fromStdWString(L"بيانات")), QString(QString::fromStdWString(L"لا يوجد سلعة بهذا الكود")),QMessageBox::Warning,QMessageBox::Ok,0,0);
        msgBox.exec();
        clearTexts();
        return;
    }

    mUi.productNameTextEdit->setText(QString::fromStdWString(item->getTypeName()));
    mUi.ProviderNameLineEdit->setText(QString::fromStdWString(item->getCompanyName()));
    mUi.priceLineEdit->setText(QString::number(item->getPrice()));
}

void InqueryDialog::on_actionBack_triggered()
{
    accept();
    clearTexts();
}

void InqueryDialog::on_actionDelete_triggered()
{
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