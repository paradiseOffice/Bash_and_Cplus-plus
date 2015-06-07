#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Texteditor; 

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToLine();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void jotterModified();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);
    // void showGrid();

    Texteditor *texteditor;
    FindDialog *findDialog;
    QLabel *locationLabel;
    QStringList recentFiles;
    QString curFile;

    enum { MaxRecentFiles = 15 };
    QAction *recentFileActions[MaxRecentFiles];
    QAction *separatorAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *recentFilesSubMenu;
    QMenu *helpMenu;

    QToolBar *commonBar;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *closeAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;
    QAction *selectAllAction;
    QAction *findAction;
    QAction *goToLineAction;
    QAction *syntaxCppAction;
    QAction *setTabsAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
};

#endif

