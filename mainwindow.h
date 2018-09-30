#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "finddialog.h"
#include <QMainWindow>

class QSessionManager;
class QTextEdit;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();
    void closeEvent(QCloseEvent *event) override;
    bool askToSave();
    bool saveFile(const QString& fileName);
    void loadFile(const QString& fileName);
    void setCurrentFile(const QString& fileName);
private slots:
    void newFile();
    void openFile();
    bool save();
    bool saveAs();
    void pageSetup();
    void print();
    void findText();
    void findNextText();
    void replace();
    void goTo();
    void timeDate();
    void wordWrap(bool);
    void editFont();
    void showStatusBar(bool checked);
    void viewHelp();
    void about();
    void deleteSelection();
    void documentWasModified();
    void writeSettings();
    void readSettings();
    void commitData(QSessionManager &manager);



private:
    QTextEdit* textEdit;
    QString currentFile;
};

#endif // MAINWINDOW_H
