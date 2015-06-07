#include <QtGui>
#include "find/finddialog.h"
#include "gotocell/gotocelldialog.h"
#include "mainwindow.h"
#include "sort/sortdialog.h"
#include "spreadsheet.h"

MainWindow::MainWindow()
{
   
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    findDialog = 0;

    setWindowIcon(QIcon(":/images/icon.jpg"));
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
    newAction->setStatusTip(tr("Create a new spreadsheet"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/images/open_file_128x128.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a spreadsheet"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save_file_128x128.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the file"));
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
    closeAction->setStatusTip(tr("Close the sheet"));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl + Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/cut_128x128.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut out text, to be moved somewhere else"));
    connect(cutAction, SIGNAL(triggered()), spreadsheet, SLOT(cutItem()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/copy_128x128.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy text leaving the original value there. "));
    connect(copyAction, SIGNAL(triggered()), spreadsheet, SLOT(copyItem()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/images/paste_128x128.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste text that has been cut or copied earlier"));
    connect(pasteAction, SIGNAL(triggered()), spreadsheet, SLOT(pasteItem()));

    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setIcon(QIcon(":/images/delete_128x128.png"));
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("Delete some cells"));
    connect(deleteAction, SIGNAL(triggered()), spreadsheet, SLOT(deleteItem()));

    selectRowAction = new QAction(tr("Select &Row"), this);
    selectRowAction->setStatusTip(tr("Select cells in a row going across"));
    connect(selectRowAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentRow()));

    selectColumnAction = new QAction(tr("Select &Column"), this);
    selectColumnAction->setStatusTip(tr("Select cells in a downwards column"));
    connect(selectColumnAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentColumn()));

    selectAllAction = new QAction(tr("&All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all cells in the sheet"));
    connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));

    findAction = new QAction(tr("&Find"), this);
    findAction->setIcon(QIcon(":/images/find_128x128.png"));
    findAction->setShortcut(tr("Ctrl + F"));
    findAction->setStatusTip(tr("Find text or numbers"));
    connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

    goToCellAction = new QAction(tr("&Go to Cell"), this);
    goToCellAction->setIcon(QIcon(":/images/goto_128x128.png"));
    goToCellAction->setShortcut(tr("Ctrl + G"));
    goToCellAction->setStatusTip(tr("Move to a cell reference"));
    connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));

    recalculateAction = new QAction(tr("&Recalculate"), this);
    recalculateAction->setShortcut(tr("F9"));
    recalculateAction->setStatusTip(tr("Updates all the math sums"));
    connect(recalculateAction, SIGNAL(triggered()), spreadsheet, SLOT(recalculate()));

    sortAction = new QAction(tr("&Sort"), this);
    sortAction->setStatusTip(tr("Sort columns in alphabetical order"));
    connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(true);
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
    connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));

    autoRecalcAction = new QAction(tr("&Auto Recalc"), this);
    autoRecalcAction->setCheckable(true);
    autoRecalcAction->setStatusTip(tr("Automatically update the maths formula "));
    connect(autoRecalcAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(autoRecalc()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setIcon(QIcon(":/images/icon.jpg"));
    aboutAction->setStatusTip(tr("Who made this program and the version number"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's box - the underlying widget system"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    for (int i = 0; i < MaxRecentFiles; ++i)
	fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAction);
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));
    selectSubMenu->addAction(selectRowAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalcAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(updateStatusBar()));
    connect(spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));
    updateStatusBar();
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified()
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
	int r = QMessageBox::warning(this, tr("Spreadsheet"), tr("The document has been modified. \n Do you want to save your changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
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
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open sheet"), ".", tr("Spreadsheet files (*.sp)"));
	if (!fileName.isEmpty()) 
            loadFile(fileName);
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    if (!spreadsheet->readFile(fileName)) {
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
    if (!spreadsheet->writeFile(fileName)) {
	statusBar()->showMessage(tr("Saving cancelled"), 2000);
	return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save spreadsheet"), ".", tr("Spreadsheet files (*.sp)"));
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
    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
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
    separatorAction->setVisible(!recentFiles.isEmpty());
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
        connect(findDialog, SIGNAL(findNext(const QString &, Qt::CaseSensitivity)), spreadsheet, SLOT(findNext(const QString &, Qt::CaseSensitivity)));
        connect(findDialog, SIGNAL(findPrevious(const QString &, Qt::CaseSensitivity)), spreadsheet, SLOT(findPrevious(const QString &, Qt::CaseSensitivity)));
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();
}

void MainWindow::goToCell()
{
    GoToCellDialog dialog(this);
    if (dialog.exec()) {
	QString str = dialog.lineEdit->text().toUpper();
	spreadsheet->setCurrentCell(str.mid(1).toInt() - 1, str[0].unicode() - 'A');
    }
}

void MainWindow::sort()
{
    SortDialog dialog(this);
    QTableWidgetSelectionRange range = spreadsheet->selectedRange();
    dialog.setColumnRange('A' + range.leftColumn(), 'A' + range.rightColumn());
    if (dialog.exec()) {
	SpreadsheetCompare compare;
	compare.keys[0] = dialog.primaryColumnCombo->currentIndex();
	compare.keys[1] = dialog.secondaryColumnCombo->currentIndex() - 1;
	compare.keys[2] = dialog.tertiaryColumnCombo->currentIndex() - 1;
	compare.ascending[0] = (dialog.primaryOrderCombo->currentIndex() == 0);
	compare.ascending[1] = (dialog.secondaryOrderCombo->currentIndex() == 0);
	compare.ascending[2] = (dialog.tertiaryOrderCombo->currentIndex() == 0);
        spreadsheet->sort(compare);
    }
}  

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Grids"), tr("<h2>Grids 0.1</h2" "<p>GNU GPL 2 Paradise Office </p><p>A basic spreadsheet for simple calculations and with extra formatting tools. See the Abacus program for more maths formula. </p>"));
}

void MainWindow::writeSettings()
{
    QSettings settings("Paradise Office", "Grids");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles);
    settings.setValue("showGrid", showGridAction->isChecked());
    settings.setValue("autoRecalc", autoRecalcAction->isChecked());
}

void MainWindow::readSettings()
{
    QSettings settings("Paradise Office", "Grids");
    restoreGeometry(settings.value("geometry").toByteArray());
    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();

    bool showGrid = settings.value("showGrid", true).toBool();
    showGridAction->setChecked(showGrid);

    bool autoRecalc = settings.value("autoRecalc", true).toBool();
    autoRecalcAction->setChecked(autoRecalc);
}

