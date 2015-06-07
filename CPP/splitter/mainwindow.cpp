/****************************************************************************
 **
 ** Jotter, part of the Paradise Office suite.
 ** Copyright (C) Hazel Windle, Digia Plc
 **
 ** This program is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU General Public License
 ** as published by the Free Software Foundation; either version 2
 ** of the License, or (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 ** Also add information on how to contact you by electronic and paper mail.
 **
 ****************************************************************************/

#include "textedit.h"
#include "tabWidth.h"
#include "changeFont/changeFont.h"

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QFont>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QFontDialog>
#include <QMenu>
#include <QMenuBar>
#include <QPrintDialog>
#include <QPrinter>
#include <QTabWidget>
#include <QToolBar>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QPrintPreviewDialog>

#ifdef Q_WS_MAC // change these to the two separate theme dirs.
const QString rsrcPath = ":/images/mac";
#else
const QString rsrcPath = ":/images/win";
#endif

MainWindow::MainWindow(QWidget *parent)
     : QMainWindow(parent)
{
    tabWidget = new QTabWidget(this);
    setToolButtonStyle(Qt::ToolButtonFollowStyle);
    setupFileActions();
    setupEditActions();
    setupOptions();
    

    {
        QMenu *helpMenu = new QMenu(tr("Help"), this);
        menuBar()->addMenu(helpMenu);
        helpMenu->addAction(tr("About"), this, SLOT(about()));
        helpMenu->addAction(tr("About &Qt"), qApp, SLOT(aboutQt()));
    }
    setWindowIcon(QIcon(rsrcPath + "/logo32.png"));

    QString initialFile = "";
    const QStringList args = QCoreApplication::arguments();
    if (args.count() == 2)
        initialFile = args.at(1);

    if (!load(initialFile))
        fileNew();
    loadTab(initialFile);

    setCurrentFileName(QString());
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (askForSave())
        e->accept();
    else
        e->ignore();
}

void MainWindow::setupTextSlots()
{
    // The connect bits for document modification
    connect(textAreas[currentTab()]->document(), SIGNAL(modificationChanged(bool)),
             actionSave, SLOT(setEnabled(bool)));
    connect(textAreas[currentTab()]->document(), SIGNAL(modificationChanged(bool)),
             this, SLOT(setWindowModified(bool)));
    connect(textAreas[currentTab()]->document(), SIGNAL(undoAvailable(bool)),
             actionUndo, SLOT(setEnabled(bool)));
    connect(textAreas[currentTab()]->document(), SIGNAL(redoAvailable(bool)),
             actionRedo, SLOT(setEnabled(bool)));

    setWindowModified(textAreas[currentTab()]->document()->isModified());
    actionSave->setEnabled(textAreas[currentTab()]->document()->isModified());
    actionUndo->setEnabled(textAreas[currentTab()]->document()->isUndoAvailable());
    actionRedo->setEnabled(textAreas[currentTab()]->document()->isRedoAvailable());

    connect(actionUndo, SIGNAL(triggered()), textAreas[currentTab()], SLOT(undo()));
    connect(actionRedo, SIGNAL(triggered()), textAreas[currentTab()], SLOT(redo()));

    actionCut->setEnabled(false);
    actionCopy->setEnabled(false);

    connect(actionCut, SIGNAL(triggered()), textAreas[currentTab()], SLOT(cut()));
    connect(actionCopy, SIGNAL(triggered()), textAreas[currentTab()], SLOT(copy()));
    connect(actionPaste, SIGNAL(triggered()), textAreas[currentTab()], SLOT(paste()));

    connect(textAreas[currentTab()], SIGNAL(copyAvailable(bool)), actionCut, SLOT(setEnabled(bool)));
    connect(textAreas[currentTab()], SIGNAL(copyAvailable(bool)), actionCopy, SLOT(setEnabled(bool)));

#ifndef QT_NO_CLIPBOARD
     connect(QApplication::clipboard(), SIGNAL(dataChanged()), this, SLOT(clipboardDataChanged()));
 #endif
}

void MainWindow::setupFileActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    QIcon newIcon = QIcon(rsrcPath + "/filenew.png");
    a = new QAction( newIcon, tr("&New"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(QIcon(rsrcPath + "/fileopen.png"),
                     tr("&Open"), this);
    a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    menu->addSeparator();

    actionSave = a = new QAction(QIcon(rsrcPath + "/filesave.png"),
                                  tr("&Save"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
    a->setEnabled(false);
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("Save &As..."), this);
    a->setPriority(QAction::LowPriority);
    connect(a, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
    menu->addAction(a);
    menu->addSeparator();

    menu->addSeparator();


    a = new QAction(tr("&Quit"), this);
    a->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(a, SIGNAL(triggered()), this, SLOT(close()));
    menu->addAction(a);
}

void MainWindow::setupEditActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("Edit"));
    addToolBar(tb);
    QMenu *menu = new QMenu(tr("&Edit"), this);
    menuBar()->addMenu(menu);

    QAction *a;
    a = actionUndo = new QAction(QIcon(rsrcPath + "/editundo.png"),
                                               tr("&Undo"), this);
    a->setShortcut(QKeySequence::Undo);
    tb->addAction(a);
    menu->addAction(a);
    a = actionRedo = new QAction(QIcon(rsrcPath + "/editredo.png"),
                                               tr("&Redo"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::Redo);
    tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();
    a = actionCut = new QAction(QIcon(rsrcPath + "/editcut.png"),
                                              tr("Cu&t"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::Cut);
    tb->addAction(a);
    menu->addAction(a);
    a = actionCopy = new QAction(QIcon(rsrcPath + "/editcopy.png"),
                                  tr("&Copy"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::Copy);
    tb->addAction(a);
    menu->addAction(a);
    a = actionPaste = new QAction(QIcon(rsrcPath + "/editpaste.png"),
                                   tr("&Paste"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::Paste);
    tb->addAction(a);
    menu->addAction(a);
#ifndef QT_NO_CLIPBOARD
    if (const QMimeData *md = QApplication::clipboard()->mimeData())
        actionPaste->setEnabled(md->hasText());
#endif
}

void MainWindow::setupOptions()
{
    QMenu *menu = new QMenu(tr("&Options"), this);
    menuBar()->addMenu(menu);

    QAction *a;
    a = actionTabWidth = new QAction(QIcon(rsrcPath + "/tab_width.png"),
                                               tr("&Tab Width"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(setTabWidth()));
    menu->addAction(a);
    a = actionChangeFont = new QAction(QIcon(rsrcPath + "/set_font.png"), tr("&Change Font"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(changeFontDialog()));
    menu->addAction(a);
}

bool MainWindow::load(const QString &f)
{
    if (!QFile::exists(f))
        return false;
    QFile file(f);
    if (!file.open(QFile::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    QTextCodec *codec = Qt::codecForHtml(data);
    QString str = codec->toUnicode(data);
    if (Qt::mightBeRichText(str)) {
        loadTab(str);
    } else {
        str = QString::fromLocal8Bit(data);
        loadTab(str);
    }

    setCurrentFileName(f);
    return true;
}

bool MainWindow::askForSave()
{
    if (!textAreas[currentTab()]->document()->isModified())
        return true;
    if (fileName.startsWith(QLatin1String(":/")))
        return true;
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Jotter"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard
                               | QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
        return fileSave();
    else if (ret == QMessageBox::Cancel)
        return false;
    return true;
}

void MainWindow::setCurrentFileName(const QString &fileName)
{
    this->fileName = fileName;
    textAreas[currentTab()]->document()->setModified(false);

    QString shownName;
    if (fileName.isEmpty())
        shownName = "new.txt";
    else
        shownName = QFileInfo(fileName).fileName();

    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Jotter")));
    setWindowModified(false);
}

void MainWindow::fileNew()
{
    if (askForSave()) {
        textAreas[currentTab()]->clear();
        setCurrentFileName(QString());
    }
}

void MainWindow::fileOpen()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File"),
                                               QString(), tr("C++ Files (*.cpp *.h *.hpp);;All Files (*)"));
    if (!fn.isEmpty())
        load(fn);
}

bool MainWindow::fileSave()
{
    if (fileName.isEmpty())
        return fileSaveAs();

    QTextDocumentWriter writer(fileName);
    bool success = writer.write(textEdit->document());
    if (success)
        textAreas[currentTab()]->document()->setModified(false);
    return success;
}

int currentTab()
{
    int index = -1;
    index = tabWidget->currentIndex();
    if (index >= 0)
        return index;
}

bool MainWindow::fileSaveAs()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save As"),
                                              QString(), tr("C++ Files (*.cpp *.h *.hpp);;All Files (*)"));
    if (fn.isEmpty())
        return false;
    if (! (fn.endsWith(".cpp", Qt::CaseInsensitive) || fn.endsWith(".hpp", Qt::CaseInsensitive) || fn.endsWith(".c", Qt::CaseInsensitive)) )
        fn += ".txt"; // default
    setCurrentFileName(fn);
    return fileSave();
}

// void setupTabRow()
// QWidget *textAreas[] = new TextEdit(this);
// for 1 time only
// 
// tabWidget->setCurrentWidget(textAreas[0]);
// 
