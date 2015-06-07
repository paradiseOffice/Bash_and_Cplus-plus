#ifndef GOTOLINEDIALOG_H
#define GOTOLINEDIALOG_H

#include <QtWidgets/QDialog>
#include "ui_gotolinedialog.h"

class GoToLineDialog : public QDialog, public Ui::GoToLineDialog
{
    Q_OBJECT
public:
    GoToLineDialog(QWidget *parent = 0);

private slots:
    void on_lineEdit_textChanged();
};

#endif
