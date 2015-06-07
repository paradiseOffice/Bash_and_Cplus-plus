#include <QtGui>
#include "find/finddialog.h"
#include "gotoline/gotolinedialog.h"
#include "mainwindow.h"
#include "texteditor.h"

MainWindow::MainWindow()
{
   
    texteditor = new Texteditor;
    setCentralWidget(texteditor);

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    findDialog = 0;

    setWindowIcon(QIcon(":/images/jotter_128x128.png"));
    setCurrentFile("");
    setAttribute(Qt::WA_DeleteOnClose);

    foreach (QWidget *win, QApplication::topLevelWidgets()) {
	if (MainWindow *mainWin = qobject_cast<MainWindow *>(win))
	    mainWin->updateRecentFileActions();
    }
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new_file_128x128.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/images/open_file_128x128.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save_file_128x128.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As"), this);
    saveAsAction->setIcon(QIcon(":/images/save_as_128x128.png"));
    saveAsAction->setStatusTip(tr("Rename the file or save as a copy"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    for (int i = 0; i < MaxRecentFiles; ++i) {
	recentFileActions[i] = new QAction(this);
	recentFileActions[i]->setVisible(false);
	connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }
    closeAction = new QAction(tr("&Close"), this);
    closeAction->setShortcut(tr("Ctrl + W"));
    closeAction->setStatusTip(tr("Close this text file only"));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl + Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/cut_128x128.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut out text, to be moved somewhere else"));
    connect(cutAction, SIGNAL(triggered()), texteditor, SLOT(cutItem()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/copy_128x128.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy text leaving the original value there. "));
    connect(copyAction, SIGNAL(triggered()), texteditor, SLOT(copyItem()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/images/paste_128x128.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste text that has been cut or copied earlier"));
    connect(pasteAction, SIGNAL(triggered()), texteditor, SLOT(pasteItem()));

    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setIcon(QIcon(":/images/delete_128x128.png"));
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("Delete some cells"));
    connect(deleteAction, SIGNAL(triggered()), texteditor, SLOT(deleteItem()));

    selectAllAction = new QAction(tr("Select &All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all cells in the sheet"));
    connect(selectAllAction, SIGNAL(triggered()), texteditor, SLOT(selectAll()));

    findAction = new QAction(tr("&Find"), this);
    findAction->setIcon(QIcon(":/images/find_128x128.png"));
    findAction->setShortcut(tr("Ctrl + F"));
    findAction->setStatusTip(tr("Find text or numbers"));
    connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

    goToLineAction = new QAction(tr("&Go to Line"), this);
    goToLineAction->setIcon(QIcon(":/images/goto_128x128.png"));
    goToLineAction->setShortcut(tr("Ctrl + G"));
    goToLineAction->setStatusTip(tr("Move to Line x"));
    connect(goToLineAction, SIGNAL(triggered()), this, SLOT(goToLine()));

    syntaxCppAction = new QAction(tr("&C++ highlighting"), this);
    syntaxCppAction->setStatusTip(tr("Syntax highlighting for C++ source code"));
    connect(syntaxCppAction, SIGNAL(triggered()), texteditor, SLOT(syntaxCpp()));

    setTabsAction = new QAction(tr("Set &Tab Width"), this);
    setTabsAction->setStatusTip(tr("Alter the tab width"));
    connect(setTabsAction, SIGNAL(triggered()), texteditor, SLOT(setTabWidth()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setIcon(QIcon(":/images/icon.jpg"));
    aboutAction->setStatusTip(tr("About Jotter and Paradise Office"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("The underlying widget system"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    recentFilesSubMenu = fileMenu->addMenu(tr("&Recent Files"));
    for (int i = 0; i < MaxRecentFiles; ++i)
	recentFilesSubMenu->addAction(recentFileActions[i]);
    separatorAction = fileMenu->addSeparator();
    fileMenu->addAction(closeAction);
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);
    editMenu->addSeparator();
    editMenu->addAction(goToLineAction);
    editMenu->addAction(findAction);

    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(syntaxCppAction);
    viewMenu->addAction(setTabsAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
    texteditor->addAction(cutAction);
    texteditor->addAction(copyAction);
    texteditor->addAction(pasteAction);
    texteditor->addAction(goToLineAction);
    texteditor->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
    commonBar = addToolBar(tr("&Common Bar"));
    commonBar->addAction(newAction);
    commonBar->addAction(openAction);
    commonBar->addAction(saveAction);
    commonBar->addSeparator();
    commonBar->addAction(cutAction);
    commonBar->addAction(copyAction);
    commonBar->addAction(pasteAction);
    commonBar->addSeparator();
    commonBar->addAction(syntaxCppAction);
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel(" 999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    statusBar()->addWidget(locationLabel);
    connect(texteditor, SIGNAL(currentLineChanged(int)), this, SLOT(updateStatusBar()));
    connect(texteditor, SIGNAL(modified()), this, SLOT(texteditorModified()));
    updateStatusBar();
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(texteditor->currentLine());
}

void MainWindow::texteditorModified()
{
    setWindowModified(true);
    updateStatusBar();
}

void MainWindow::newFile()
{
    MainWindow *mainWin = new MainWindow;
    mainWin->show();
}

bool MainWindow::okToContinue()
{
    if (isWindowModified()) {
	int r = QMessageBox::warning(this, tr("Jotter"), tr("The text has been changed. \n Do you want to save your changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
	if (r == QMessageBox::Yes) {
            return save();
	} else if (r == QMessageBox::Cancel) {
	    return false;
	} 
    }
    return true;
}

void MainWindow::open()
{
    if (okToContinue()) {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text files (*.txt *.cpp *.h *.hpp)"));
	if (!fileName.isEmpty()) 
            loadFile(fileName);
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    if (!texteditor->readFile(fileName)) {
	statusBar()->showMessage(tr("Loading cancelled"), 2000);
	return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    return true;
}

bool MainWindow::save()
{
    if (curFile.isEmpty()) {
	return saveAs();
    } else {
	return saveFile(curFile);
    }
}
bool MainWindow::saveFile(const QString &fileName)
{
    if (!texteditor->writeFile(fileName)) {
	statusBar()->showMessage(tr("Saving cancelled"), 2000);
	return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), ".", tr("Text files (*.txt *.cpp *.hpp *.h )"));
    if (fileName.isEmpty())
	return false;
    return saveFile(fileName);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (okToContinue()) {
	writeSettings();
	event->accept();
    } else {
	event->ignore();
    }
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false);
    QString shownName = tr("Untitled");
    if (!curFile.isEmpty()) {
	shownName = strippedName(curFile);
	recentFiles.removeAll(curFile);
	recentFiles.prepend(curFile);
	updateRecentFileActions();
    }
    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Jotter")));
}
QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);
    while (i.hasNext()) {
	if (!QFile::exists(i.next()))
	    i.remove();
    }

    for (int j = 0; j < MaxRecentFiles; ++j) {
	if (j < recentFiles.count()) {
	    QString text = tr("%1 %2").arg(j + 1).arg(strippedName(recentFiles[j]));
	    recentFileActions[j]->setText(text);
	    recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
	} else {
	    recentFileActions[j]->setVisible(false);
	}
    }
    // separatorAction->setVisible(!recentFiles.isEmpty());
}

void MainWindow::openRecentFile()
{
    if (okToContinue()) {
	QAction *action = qobject_cast<QAction *>(sender());
	if (action) 
	    loadFile(action->data().toString());
    }
}

void MainWindow::find()
{
    if (!findDialog) {	
        findDialog = new FindDialog(this);
        connect(findDialog, SIGNAL(findNext(const QString &, Qt::CaseSensitivity)), texteditor, SLOT(findNext(const QString &, Qt::CaseSensitivity)));
        connect(findDialog, SIGNAL(findPrevious(const QString &, Qt::CaseSensitivity)), texteditor, SLOT(findPrevious(const QString &, Qt::CaseSensitivity)));
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();
}

void MainWindow::goToLine()
{
    int line_no = 0;
    GoToLineDialog dialog(this);
    if (dialog.exec()) {
	line_no = dialog.lineEdit->text().toInt();
        QTextCursor new_line(texteditor->findBlockByLineNumber( line_no - 1 ));
        new_line.select(QTextCursor::LineUnderCursor);
	texteditor->setTextCursor(new_line);
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Jotter"), tr("<h2>Jotter 0.1</h2" "<p>GNU GPL 2 Paradise Office </p><p>Another programmer's text editor. You can never have enough text editors! :-) </p>"));
}

void MainWindow::writeSettings()
{
    QSettings settings("Paradise Office", "Jotter");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles);
}

void MainWindow::readSettings()
{
    QSettings settings("Paradise Office", "Jotter");
    restoreGeometry(settings.value("geometry").toByteArray());
    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();

}


