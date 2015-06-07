#include <QtGui>
#include "texteditor.h"

Texteditor::Texteditor(QWidget *parent) : QTextEdit(parent)
{
    texteditor->setAcceptRichText(false);
    QFont font("Liberation Mono", 10);
    texteditor->setCurrentFont( &initialFont );

    connect(this, SIGNAL(textChanged(QTextEdit *)), this, SLOT(somethingChanged()));
    texteditor->clear();
}

bool Texteditor::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Tab) {
            insertAtCurrentPosition('    ');
            return true;
        }
    }
    return QWidget::event(event);
}

QString Texteditor::currentLocation() const
{
    return QTextEdit->textCursor();
}

void Texteditor::somethingChanged()
{
}

bool Texteditor::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
	QMessageBox::warning(this, tr("Jotter"), tr("Cannot write file %1: \n %2.").arg(file.fileName()).arg(file.errorString()));
	return false;
    }
    QTextStream out(&file);
    // out.setVersion(QTextStream::Qt_4_8);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
    QApplication::restoreOverrideCursor();
    return true;
}

bool Texteditor::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
	QMessageBox::warning(this, tr("Jotter"), tr("Cannot read file %1: \n %2.").arg(file.fileName()).arg(file.errorString()));
	return false;
    }

    QTextStream in(&file);
    // in.setVersion(QTextStream::Qt_4_8);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QApplication::restoreOverrideCursor();
    return true;
}

void Texteditor::cutItem()
{
    copyItem();
    deleteItem();
}

void Texteditor::copyItem()
{
    if (QTextCursor->hasSelection()) {
        QString str = QTextCursor->selectedText();
    }
    QApplication::clipboard()->setText(str);
}

void Texteditor::pasteItem()
{
    // QString str = QApplication::clipboard()->text();
    QTextEdit->paste();
    somethingChanged();
}

void Texteditor::deleteItem()
{
    QString str = QTextCursor->selectedText();
    delete str;
}

void Texteditor::findNext(const QString &str, Qt::CaseSensitivity cs)
{
    QString findRange;
    int findFlags = 0;

    /* if (QTextCursor->hasSelection()) {
        findRange = QTextCursor->selectedText();
    } else {
        findRange = QTextEdit->document().text();
    }
    if (cs == true) 
        findFlags = 0X00002;

    QTextEdit->find( &str, findFlags); 
    */
}

void Texteditor::findPrevious(const QString &str, Qt::CaseSensitivity cs)
{
    QString findRange;
    int findFlags = 0X000003; // backwards and case sensitive.
}

bool Texteditor::syntaxCpp() 
{
}

void setTabWidth()
{
}

