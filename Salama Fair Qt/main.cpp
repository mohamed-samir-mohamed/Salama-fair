#include <QtWidgets/QApplication>
#include "MainForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<MainForm>  mainForm = std::shared_ptr<MainForm> (new MainForm());
    mainForm->show();
    return a.exec();
}
