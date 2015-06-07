#include "atest.h"


void Atest::toUpper()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
    QCOMPARE(str.toUpper(), QString("HELLO"));
    
}
