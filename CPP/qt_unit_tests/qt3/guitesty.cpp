#include "guitesty.h"

void GuiTesty::guiTest()
{
    QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "Goldfish");
    QCOMPARE(lineEdit.text(), QString("Goldfish"));
}
