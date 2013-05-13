#include <QtGui/QApplication>
#include "calculate.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    App *foo = new App();
    foo->show();
    return app.exec();
}
