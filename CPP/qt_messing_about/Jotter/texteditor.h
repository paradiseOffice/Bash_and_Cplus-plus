#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <QTextEdit>
#include <QWidget>

class Texteditor : public QTextEdit
{
    Q_OBJECT

public:
    Texteditor(QWidget *parent = 0);

    // QString currentLocation() const;
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);
    

public slots:
    void cutItem();
    void copyItem();
    void pasteItem();
    void deleteItem();
    bool syntaxCpp();
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);
    // void setTabWidth();

signals:
    void modified();

private slots:
    void somethingChanged();
    bool event(QEvent *event);

private:
    // QString text(int row, int column) const;

};

#endif
