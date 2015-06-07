/********************************************************************************
** Form generated from reading UI file 'gotolinedialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOLINEDIALOG_H
#define UI_GOTOLINEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoToLineDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GoToLineDialog)
    {
        if (GoToLineDialog->objectName().isEmpty())
            GoToLineDialog->setObjectName(QString::fromUtf8("GoToLineDialog"));
        GoToLineDialog->resize(184, 79);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Documents/paradise_office/sandbox_v0.5/view/themes/default_pro_theme/icons/programs/jotter_64x64.png"), QSize(), QIcon::Normal, QIcon::Off);
        GoToLineDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(GoToLineDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, 5, 178, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(GoToLineDialog);

        QMetaObject::connectSlotsByName(GoToLineDialog);
    } // setupUi

    void retranslateUi(QDialog *GoToLineDialog)
    {
        GoToLineDialog->setWindowTitle(QApplication::translate("GoToLineDialog", "Go To Line", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GoToLineDialog", "&Line number:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GoToLineDialog: public Ui_GoToLineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOLINEDIALOG_H
