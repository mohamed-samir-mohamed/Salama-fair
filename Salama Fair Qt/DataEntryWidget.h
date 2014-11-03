#ifndef DATA_ENTY_WIDGET_H
#define DATA_ENTY_WIDGET_H
#include <QWidget>
#include "GeneratedFiles\ui_DataEntryWidget.h"
#include "Item.h"
#include <memory>

class DataEntryWidget: public QWidget
{
public:
    DataEntryWidget(QWidget* parent = nullptr, Qt::ItemFlags flags = 0);
    ~DataEntryWidget();

private slots:
    void on_actionEnter_triggered();
    void on_actionExit_triggered();

private:

    Ui::DataEntryWidget mUi;

    std::vector<shared_ptr<Item>> mItems;
};

#endif