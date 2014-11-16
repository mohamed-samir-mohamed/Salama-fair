#ifndef DATA_ENTY_WIDGET_H
#define DATA_ENTY_WIDGET_H
#include <QWidget>
#include "GeneratedFiles\ui_DataEntryDialog.h"
#include <memory>


class QCloseEvent;
class Item;

class DataEntryDialog: public QDialog
{
    Q_OBJECT

public:
    DataEntryDialog(QWidget* parent = nullptr, Qt::ItemFlags flags = 0);
    ~DataEntryDialog();
    std::vector<std::shared_ptr<Item>> getItems() const;

protected:
    void closeEvent(QCloseEvent* fCloseEvent);

private slots:
    void on_actionEnter_triggered();
    void on_actionBack_triggered();

private:

    Ui::DataEntryDialog mUi;
    std::vector<std::shared_ptr<Item>> mItems;
};
#endif// !DATA_ENTY_WIDGET_H