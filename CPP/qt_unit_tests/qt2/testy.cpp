#include "testy.h"

void Testy::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
    QTest::newRow("a number") << "heLlo3" << "HELLO";    
}

void Testy::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);
    
    QCOMPARE(string.toUpper(), result);
}
