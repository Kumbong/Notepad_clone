#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialogs/finddialog.h"
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
    //creates the actions for the menu bar calls the different
    //action creaters for each menu item
    //The menu bar is filled with actions after it is called
    void closeEvent(QCloseEvent *event) override;
    //event handler for close event
    //If there is a currently open file that has unsave work
    //asks the user if the work should be saved before closing
    bool askToSave();
    //function for requesting from a user if the file should be saved
    bool saveFile(const QString& fileName);
    //saves the work in the file specified by fileName
    void loadFile(const QString& fileName);
    //checks if the file exists and can be open and the opens the file
    //and reads the information in the file
    void setCurrentFile(const QString& fileName);
    //se tthe current file being used in the editor
    //changes the file name on the editor title
    void createFileActions();
    //create file actions for the file menu item
    void createEditActions();
    //create actions for the edit menu item
    void createFormatActions();
    //create actions for the format menu item
    void createViewActions();
    //create actions for the the view menu item
    void createHelpActions();
    //create actions for the help menu item

private slots:
    void newFile();
    //asks if the current file should be saved if necessary and then
    //creates and opens a new unsaved file
    void openFile();
    //asks if the current file should be saved if necessary and then
    //loads a file menu dialog to open a file
    bool save();
    //calls save as if the file has not been saved before
    //saves the file and returns a boolean to represent the save status
    //True if successfully saved and false otherwise
    bool saveAs();
    //launches a file menu dialog with options to save the current file
    //returns true if the file is save and false if otherwise

    //not implemented yet
    void pageSetup();
    void print();
    void findText();
    void findNextText();
    void replace();
    void goTo();
    //raises a dialog that accepts a dialog the user wants to go to
    void timeDate();
    //prints the time and date to the QText Edit
    void wordWrap(bool);
    //if the parameter is true then the QTextEdit is set to word wrap and
    //not if otherwise
    void editFont();
    //opens a dialog with several font options the user can interact with
    void showStatusBar(bool checked);
    //displays the status bar if checked is true and does not do so if otherwise
    //checks the status bar action in the menu bar
    void viewHelp();
    //display help options for the application
    void about();
    //display a messagebox with information about the product
    void deleteSelection();
    //delete the current selection of words from the text edit
    void documentWasModified();
    //show an asterisk at the end of the file name to indicate the document was identified
    //update the word count and render to the status bar if necessary
    void readSettings();
    //reads the stored application settings at the start of the program
    //reverts to defaults if the settings have not been set
    void writeSettings();
    //write settings like font and geometry to the system at close of program
    void commitData(QSessionManager &manager);
    //application wide session manager



private:
    QTextEdit* textEdit;
    QString currentFile;
    QFont font;
    bool statusBarIsOn;
    int wordCount;
};

#endif // MAINWINDOW_H
