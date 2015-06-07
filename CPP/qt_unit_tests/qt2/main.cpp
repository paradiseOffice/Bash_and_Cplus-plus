#include "testrunner.h"
#include "testy.h" // QTest compatible class 
#include <QDebug>

int main() {
    TestRunner testRunner;
    testRunner.addTest(new Testy()); //your QTest compatible class here
    qDebug() << "Unit Test result: " << (testRunner.runTests()? "PASS :-D" : "FAIL :-<");

    return 0;
}
