#ifndef MAIN_FORM_H
#define MAIN_FORM_H
#include <QWidget>
#include "GeneratedFiles\ui_MainForm.h"
#include <memory>

class DataEntryDialog;
class InqueryDialog;

class MainForm: public QWidget
{
    Q_OBJECT
public:
    MainForm(QWidget* parent = nullptr, Qt::ItemFlags flags = 0);

private slots:
    void on_actionDataEntry_triggered();
    void on_actionInqueryAndEdit_triggered();
    void on_actionCreateBill_triggered();

private:
    Ui::MainForm mUi;
    std::shared_ptr<DataEntryDialog> mDataEntryDialog;
    std::shared_ptr<InqueryDialog> mInqueryDialog;

};
#endif// !MAIN_FORM