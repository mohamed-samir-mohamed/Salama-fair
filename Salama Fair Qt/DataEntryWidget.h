#ifndef DATA_ENTY_WIDGET_H
#define DATA_ENTY_WIDGET_H
#include <QWidget>
#include "GeneratedFiles\ui_DataEntryWidget.h"
#include <memory>


class QCloseEvent;
class Item;

class DataEntryWidget: public QWidget
{
    Q_OBJECT

public:
    DataEntryWidget(QWidget* parent = nullptr, Qt::ItemFlags flags = 0);
    ~DataEntryWidget();
    std::vector<shared_ptr<Item>> getItems() const;

protected:
    void closeEvent(QCloseEvent* fCloseEvent);

private slots:
    void on_actionEnter_triggered();
    void on_actionExit_triggered();

private:

    Ui::DataEntryWidget mUi;
    std::vector<shared_ptr<Item>> mItems;
};
#endif// !DATA_ENTY_WIDGET_H