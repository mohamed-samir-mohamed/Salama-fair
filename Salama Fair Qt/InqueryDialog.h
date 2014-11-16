#ifndef INQUERYDIALOG_H
#define INQUERYDIALOG_H
#include <QDialog>
#include "GeneratedFiles\ui_InqueryDialog.h"

class InqueryDialog : public QDialog
{
    Q_OBJECT
public:
    InqueryDialog(QWidget* parent = nullptr, Qt::ItemFlags flags = 0);
    ~InqueryDialog();

private slots:

    void on_actionInquery_triggered();
    void on_actionEdit_triggered();
    void on_actionBack_triggered();
    void on_actionDelete_triggered();

private:
    Ui::InqueryDialog mUi;

    void clearTexts();
    void enableTexts(bool fEnable = true);

};

#endif// !INQUERYDIALOG