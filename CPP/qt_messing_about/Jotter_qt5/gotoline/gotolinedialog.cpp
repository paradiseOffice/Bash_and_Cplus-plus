#include <QtGui>
#include "gotolinedialog.h"

GoToLineDialog::GoToLineDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regExp("[0-9]");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void GoToLineDialog::on_lineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
