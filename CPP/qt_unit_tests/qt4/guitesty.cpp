#include "guitesty.h"

void GuiTesty::guiTest_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");
    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";
    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << list2 << "";
    QTestEventList list3;
    list3.addKeyClick('G');
    list3.addKeyClick('o');
    list3.addKeyClick('l');
    list3.addKeyClick('d');
    list3.addKeyClick('f');
    list3.addKeyClick('i');
    list3.addKeyClicks("sh");
    list3.addKeyClick('y');
    QTest::newRow("Goldfishy") << list3 << "Goldfishy" ;
    
}

void GuiTesty::guiTest()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);
    
    QLineEdit lineEdit;
    
    events.simulate(&lineEdit);
    QCOMPARE(lineEdit.text(), expected);
}
