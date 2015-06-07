#include "gui_testrunner.h"
#include "guitesty.h" // QTest compatible class 
#include <QDebug>

int main() {
    TestRunner testRunner;
    testRunner.addTest(new GuiTesty()); //your QTest compatible class here
    qDebug() << "Unit Test result: " << (testRunner.runTests()? "PASS :-D" : "FAIL :-<");

    return 0;
}
