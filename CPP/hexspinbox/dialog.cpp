#include <QtGui>
#include "hexdialog.h"
#include "hexspinbox.h"

HexDialog::HexDialog(QWidget *parent) : QDialog(parent)
{
    label = new QLabel(tr("&Hex value:"));
    hexBox = new HexSpinBox();
    closeButton = new QPushButton(tr("Close"));

    connect(closeButton, SIGNAL(triggered()), this, SLOT(close()));
}
