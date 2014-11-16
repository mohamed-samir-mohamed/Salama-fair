#include "MainForm.h"
#include "DataEntryDialog.h"
#include "InqueryDialog.h"

MainForm::MainForm(QWidget* parent, Qt::ItemFlags flags )
{
    mUi.setupUi(this);
    mDataEntryDialog = std::shared_ptr<DataEntryDialog>(new DataEntryDialog(this));
    mInqueryDialog = std::shared_ptr<InqueryDialog>(new InqueryDialog(this));

}

void MainForm:: on_actionDataEntry_triggered()
{
   bool dialogExec = mDataEntryDialog->exec();
   if(dialogExec)
   {
       auto items = mDataEntryDialog->getItems();
       //save to database here.
   }
}

void MainForm::on_actionInqueryAndEdit_triggered()
{
    bool dialogExec = mInqueryDialog->exec();
}

void MainForm::on_actionCreateBill_triggered()
{

}