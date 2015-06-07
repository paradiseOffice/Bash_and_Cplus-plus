#include "testrunner.h"
#include "atest.h" // QTest compatible class 
#include <QDebug>

int main() {
    TestRunner testRunner;
    testRunner.addTest(new Atest()); //your QTest compatible class here
    qDebug() << "Unit Test result: " << (testRunner.runTests()? "PASS :-D" : "FAIL :-<");

    return 0;
}
