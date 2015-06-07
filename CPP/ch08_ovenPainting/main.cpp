#include <QApplication>

#include "oventimer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    OvenTimer ovenTimer;
    ovenTimer.setWindowTitle(QObject::tr("A Knobbly Timer"));
    ovenTimer.resize(400, 400);
    ovenTimer.show();
    return app.exec();
}

