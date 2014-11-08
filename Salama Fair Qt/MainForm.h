#ifndef MAIN_FORM
#define MAIN_FORM
#include <QWidget>
#include "GeneratedFiles\ui_MainForm.h"

class MainForm: public QWidget
{
    Q_OBJECT
public:
    MainForm(QWidget* parent = nullptr, Qt::ItemFlags flags = 0);

private slots:
    void on_actionDataEntry_Triggered();
    void on_actionInqueryAndEdit_Triggered();
    void on_actionCreateBill_Triggered();

private:
    Ui::MainForm mUi;
};
#endif// !MAIN_FORM