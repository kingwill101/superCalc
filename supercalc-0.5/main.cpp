#include <QtGui/QApplication>
#include "include/calculate.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    App *superCalc = new App( "SuperCalc" );
    superCalc->show();
    return app.exec();
}
