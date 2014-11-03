/********************************************************************************
** Form generated from reading UI file 'DataEntryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAENTRYWIDGET_H
#define UI_DATAENTRYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataEntryWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *productNameLineEdit;
    QLineEdit *IDLineEdit;
    QPushButton *exitButton;
    QPushButton *enterButton;
    QLabel *label;
    QLineEdit *providerNameLineEdit;
    QLabel *label_2;
    QLineEdit *priceLineEdit;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *DataEntryWidget)
    {
        if (DataEntryWidget->objectName().isEmpty())
            DataEntryWidget->setObjectName(QStringLiteral("DataEntryWidget"));
        DataEntryWidget->resize(595, 460);
        gridLayout = new QGridLayout(DataEntryWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        productNameLineEdit = new QLineEdit(DataEntryWidget);
        productNameLineEdit->setObjectName(QStringLiteral("productNameLineEdit"));

        gridLayout->addWidget(productNameLineEdit, 1, 3, 1, 1);

        IDLineEdit = new QLineEdit(DataEntryWidget);
        IDLineEdit->setObjectName(QStringLiteral("IDLineEdit"));

        gridLayout->addWidget(IDLineEdit, 1, 5, 1, 1);

        exitButton = new QPushButton(DataEntryWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy);
        exitButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(exitButton, 3, 1, 1, 2);

        enterButton = new QPushButton(DataEntryWidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(enterButton->sizePolicy().hasHeightForWidth());
        enterButton->setSizePolicy(sizePolicy1);
        enterButton->setMinimumSize(QSize(100, 0));
        enterButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(enterButton, 3, 3, 1, 1);

        label = new QLabel(DataEntryWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(label, 1, 6, 1, 1);

        providerNameLineEdit = new QLineEdit(DataEntryWidget);
        providerNameLineEdit->setObjectName(QStringLiteral("providerNameLineEdit"));

        gridLayout->addWidget(providerNameLineEdit, 2, 5, 1, 1);

        label_2 = new QLabel(DataEntryWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 4, 1, 1);

        priceLineEdit = new QLineEdit(DataEntryWidget);
        priceLineEdit->setObjectName(QStringLiteral("priceLineEdit"));

        gridLayout->addWidget(priceLineEdit, 2, 3, 1, 1);

        label_3 = new QLabel(DataEntryWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 6, 1, 1);

        label_4 = new QLabel(DataEntryWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 4, 1, 1);


        retranslateUi(DataEntryWidget);

        QMetaObject::connectSlotsByName(DataEntryWidget);
    } // setupUi

    void retranslateUi(QWidget *DataEntryWidget)
    {
        DataEntryWidget->setWindowTitle(QApplication::translate("DataEntryWidget", "\330\265\331\201\330\255\330\251 \330\247\330\257\330\256\330\247\331\204 \330\247\331\204\330\250\331\212\330\247\331\206\330\247\330\252", 0));
        exitButton->setText(QApplication::translate("DataEntryWidget", "\330\247\331\204\330\256\330\261\331\210\330\254", 0));
        enterButton->setText(QApplication::translate("DataEntryWidget", "\330\247\330\257\330\256\331\204 \330\247\331\204\330\250\331\212\330\247\331\206\330\247\330\252", 0));
        label->setText(QApplication::translate("DataEntryWidget", "\330\247\331\204\330\261\331\202\331\205 \330\247\331\204\331\205\330\263\331\204\330\263\331\204", 0));
        label_2->setText(QApplication::translate("DataEntryWidget", "\330\247\330\263\331\205 \330\247\331\204\331\205\331\206\330\252\330\254", 0));
        label_3->setText(QApplication::translate("DataEntryWidget", "\330\247\330\263\331\205 \330\247\331\204\331\205\331\210\330\261\330\257", 0));
        label_4->setText(QApplication::translate("DataEntryWidget", "\330\247\331\204\330\263\330\271\330\261 \330\250\330\247\331\204\330\254\331\206\331\212\330\251", 0));
    } // retranslateUi

};

namespace Ui {
    class DataEntryWidget: public Ui_DataEntryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAENTRYWIDGET_H
