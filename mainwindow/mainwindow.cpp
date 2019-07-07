#include "mainwindow.h"
#include "dialogs/replacedialog.h"
#include "dialogs/gotolinedialog.h"
#include <QtWidgets>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>


//Todo
//add printing

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QTextEdit(this);
    wordCount = 0;

    createActions();
    setCentralWidget(textEdit);

    setCurrentFile(QString());

    readSettings();
    connect(textEdit->document(),&QTextDocument::contentsChanged,this,&MainWindow::documentWasModified);

    QGuiApplication::setFallbackSessionManagementEnabled(false);
    connect(qApp, &QGuiApplication::commitDataRequest,
            this, &MainWindow::commitData);

    if(statusBarIsOn){
        showStatusBar(true);
    }else{
        showStatusBar(false);
    }

}

void MainWindow::documentWasModified(){
     setWindowModified(textEdit->document()->isModified());
     wordCount = textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+")
                                                       , QString::SkipEmptyParts).count();

     if(statusBarIsOn)
        this->statusBar()->showMessage(QString::number(wordCount) + QString(" words"));


}
MainWindow::~MainWindow()
{

}

bool MainWindow::askToSave(){
    //ask the user if the current work should be saved when user attempts exit or opens new
    //file

    //don't ask if the file is not modified from the last save
    if(!isWindowModified())
        return true;

    QMessageBox msgBox;
    msgBox.setText("Do you want to save changes to the document?");//change to the document to use the proper document name
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel );
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    //return if the file was saved or not
    switch(ret){
    case QMessageBox::Save:
        return save();
    case QMessageBox::Discard:
        return true;
    default:
        break;
    }
    return false;
}
void MainWindow::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
       const QByteArray geometry = settings.value("mainwindow/geometry", QByteArray()).toByteArray();
       if (geometry.isEmpty()) {
           const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
           resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
           move((availableGeometry.width() - width()) / 2,
                (availableGeometry.height() - height()) / 2);
       } else {
           restoreGeometry(geometry);
       }
       font = settings.value("text/font", QFont()).value<QFont>();
       statusBarIsOn = settings.value("mainwindow/statusbar").toBool();
       textEdit->setFont(font);
}
void MainWindow::writeSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("mainwindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("statusbar",statusBarIsOn);
    settings.endGroup();

    settings.beginGroup("text");
    settings.setValue("font", font);
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent* event){
    //event handler for close event
    if(askToSave()){
        writeSettings();
        event->accept();
       }
    else
        event->ignore();

}
bool MainWindow::saveFile(const QString& fileName){

    //handle saving of files
    QFile file(fileName);

    //don't wtie to a read only file
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,tr("Notepad--"),tr("Cannot write file"));//edit to make use of fileName and error message
        return false;
    }
   //change the cursor while saving the file
    QTextStream out(&file);
    out<<textEdit->toPlainText();

    setCurrentFile(fileName);
    return true;
  }

bool MainWindow::save(){
    //if the file has not yet been saved, call saveAs
   if(currentFile.isEmpty())
       return saveAs();
   else
       return saveFile(currentFile);
}

bool MainWindow::saveAs(){

    //create a dialog box to get the details for the file
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Text (*.txt)"));
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAcceptMode(QFileDialog::AcceptSave);

    QString fileName;

    //if user accepts to save the save the first file if multiple are selected
    if(dialog.exec()==QDialog::Accepted){
        fileName = dialog.selectedFiles().first();
        return saveFile(fileName);
    }
    else{
        return false;
    }
}

//delete a selection of texs
void MainWindow::deleteSelection(){
      QTextCursor  cursor(textEdit->textCursor());
      cursor.removeSelectedText();
}

void MainWindow::newFile(){
    //if the user cancels the save prompt then return
    if(!askToSave())
        return;
    textEdit->clear();
    setCurrentFile(QString());
}

void MainWindow::openFile(){

    if(askToSave()){
     QFileDialog dialog(this);
     dialog.setFileMode(QFileDialog::ExistingFile);
     dialog.setNameFilter(tr("Text (*.txt);;All files (*.*)"));
     dialog.setViewMode(QFileDialog::Detail);
     dialog.setAcceptMode(QFileDialog::AcceptOpen);

     if(!dialog.exec())
         return;

     QString fileName = dialog.selectedFiles().first();

     if(!fileName.isEmpty())
         loadFile(fileName);
    }

}
void MainWindow::loadFile(const QString& fileName){

    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,tr("NotePad--"),tr("Cannot Open file"));//edit to take care of the particular file
        return;
    }

    QTextStream in(&file);
    textEdit->clear();
    textEdit->setText(in.readAll());

    setCurrentFile(fileName);
}
void MainWindow::setCurrentFile(const QString &fileName){
    currentFile = fileName;
    textEdit->document()->setModified(false);
    setWindowModified(false);

    QString showName = currentFile;

    if(currentFile.isEmpty())
        showName = "untitled.txt";
    setWindowFilePath(showName);

}
void MainWindow::pageSetup(){
    //add page setup for printing
}
void MainWindow::print(){
   //add printing here
}
void MainWindow::findText(){
    findDialog *dialog = new findDialog(this);

     if(dialog->exec()==QDialog::Accepted){
         bool caseSensitive;
         findDialog::Direction searchDirection;
         QString searchString;

         dialog->getDialogOutput(caseSensitive,searchDirection,searchString);

         QTextCursor cursor(textEdit->document());



     }


}

void MainWindow::findNextText(){

}
void MainWindow::replace(){
     replaceDialog *dialog = new replaceDialog(this);

     dialog->exec();
}
void MainWindow::goTo(){
     goToLineDialog *dialog = new goToLineDialog(this);

     dialog->setLineEditText(textEdit->textCursor().blockNumber());//work around this again
     dialog->exec();
}
void MainWindow::timeDate(){
     QDateTime dateTime(QDateTime::currentDateTime());

     QString dateTimeString =dateTime.time().toString();
     textEdit->textCursor().insertText(dateTimeString.append(" "));
     textEdit->textCursor().insertText(dateTime.date().toString());
}
void MainWindow::wordWrap(bool textWrapped){

     if(textWrapped)
        textEdit->setWordWrapMode(QTextOption::WordWrap);
     else
        textEdit->setWordWrapMode(QTextOption::NoWrap);
}
void MainWindow::editFont(){
    bool ok;
      font = QFontDialog::getFont(&ok,textEdit->font(), this);
      if (ok) {
          textEdit->setFont(font);
      }
}
void MainWindow::showStatusBar(bool checked){

    statusBarIsOn = checked;

    if(statusBarIsOn){
        statusBar()->show();
        statusBar()->showMessage(QString::number(wordCount) + QString(" words"));
    }
    else
        statusBar()->hide();
}
void MainWindow::viewHelp(){
    QMessageBox::about(this,tr("About Notepad--"),tr("<b>NotePad--</b>\n This is a light, cross platform variant "
                                                       "of the Notepad application on Windows, "));

}
void MainWindow::about(){

}

void MainWindow::commitData(QSessionManager &manager){

    if(manager.allowsInteraction()){
        if(!askToSave())
            manager.cancel();
    }else{
        if(textEdit->document()->isModified())
            save();
    }
}
void MainWindow::createFileActions(){
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *newAction = new QAction(tr("&New"),this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new file"));
    connect(newAction,&QAction::triggered,this,&MainWindow::newFile);
    fileMenu->addAction(newAction);

    QAction *openAction = new QAction(tr("&Open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open and existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);
    fileMenu->addAction(openAction);

    QAction *saveAction = new QAction(tr("&Save"),this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save Document to disk"));
    connect(saveAction,&QAction::triggered,this,&MainWindow::save);
    fileMenu->addAction(saveAction);

    QAction *saveAsAction = new QAction(tr("Save &As..."),this);
    saveAsAction->setStatusTip(tr("Save Document to disk"));
    connect(saveAsAction,&QAction::triggered,this,&MainWindow::saveAs);
    fileMenu->addAction(saveAsAction);

    fileMenu->addSeparator();

    QAction *pageSetupAction = new QAction(tr("Page Set&up..."),this);
    pageSetupAction->setStatusTip(tr("Change the format and layout of the document"));
    connect(pageSetupAction,&QAction::triggered,this,&MainWindow::pageSetup);

    //implement in late version
    //fileMenu->addAction(pageSetupAction);

    QAction *printAction = new QAction(tr("&Print"),this);
    printAction->setShortcuts(QKeySequence::Print);
    printAction->setStatusTip(tr("Print Document"));
    connect(printAction,&QAction::triggered,this,&MainWindow::print);

    //implement in later version
    //fileMenu->addAction(printAction);

    fileMenu->addSeparator();

    QAction *exitAction = new QAction(tr("E&xit"),this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction,&QAction::triggered,this,&QMainWindow::close);
    fileMenu->addAction(exitAction);
}
void MainWindow::createEditActions(){
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));

    QAction *undoAction = new QAction(tr("&Undo"),this);
    undoAction->setShortcuts(QKeySequence::Undo);
    undoAction->setStatusTip(tr("Undo changes"));
    connect(undoAction,&QAction::triggered,textEdit,&QTextEdit::undo);
    editMenu->addAction(undoAction);

    QAction *redoAction = new QAction(tr("Red&o"),this);
    redoAction->setShortcuts(QKeySequence::Redo);
    redoAction->setStatusTip(tr("Redo changes"));
    connect(redoAction,&QAction::triggered,textEdit,&QTextEdit::redo);
    editMenu->addAction(redoAction);

    editMenu->addSeparator();

    QAction *copyAction = new QAction(tr("&Copy"),this);
    copyAction->setShortcuts(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the current selection's contents to the clipboard"));
    connect(copyAction,&QAction::triggered,textEdit,&QTextEdit::copy);
    editMenu->addAction(copyAction);

    QAction *cutAction = new QAction(tr("Cu&t"),this);
    cutAction->setShortcuts(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the current selection's contents to the clipboard"));
    connect(cutAction,&QAction::triggered,textEdit,&QTextEdit::cut);
    editMenu->addAction(cutAction);

    QAction *pasteAction = new QAction(tr("&Paste"),this);
    pasteAction->setShortcuts(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents into the current selection"));
    connect(pasteAction,&QAction::triggered,textEdit,&QTextEdit::paste);
    editMenu->addAction(pasteAction);

    QAction *deleteAction = new QAction(tr("&Delete"),this);
    deleteAction->setShortcuts(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("Delete the current selection's contents"));
    connect(deleteAction,&QAction::triggered,this,&MainWindow::deleteSelection);
    editMenu->addAction(deleteAction);

    editMenu->addSeparator();

    QAction *findAction = new QAction(tr("&Find..."),this);
    findAction->setShortcuts(QKeySequence::Find);
    findAction->setStatusTip(tr("Locate a word or portion of text"));
    connect(findAction,&QAction::triggered,this,&MainWindow::findText);
    editMenu->addAction(findAction);

    QAction *findNextAction = new QAction(tr("Find &Next"),this);
    findNextAction->setShortcuts(QKeySequence::FindNext);
    findNextAction->setStatusTip(tr("Locate a word or portion of text"));
    connect(findNextAction,&QAction::triggered,this,&MainWindow::findNextText);
    editMenu->addAction(findNextAction);

    QAction *replaceAction = new QAction(tr("&Replace..."),this);
    replaceAction->setShortcuts(QKeySequence::Replace);
    replaceAction->setStatusTip(tr("Locate and replace a word or portion of text"));
    connect(replaceAction,&QAction::triggered,this,&MainWindow::replace);
    editMenu->addAction(replaceAction);

    QAction *goToAction = new QAction(tr("&Go To..."),this);
    //goToAction->setShortcuts(QKeySequence(tr("Ctrl+G")));//likely to be problematic
    goToAction->setStatusTip(tr("Go to a selected line"));
    connect(goToAction,&QAction::triggered,this,&MainWindow::goTo);
    editMenu->addAction(goToAction);
    editMenu->addSeparator();

    QAction *selectAllAction = new QAction(tr("Select &All"),this);
    selectAllAction->setShortcuts(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select the entire document"));
    connect(selectAllAction,&QAction::triggered,textEdit,&QTextEdit::selectAll);
    editMenu->addAction(selectAllAction);

    QAction *timeDateAction = new QAction(tr("Time\\&Date"),this);
    //timeDateAction->setShortcuts(Qt::Key_F5);
    timeDateAction->setStatusTip(tr("Insert date and time to document"));
    connect(timeDateAction,&QAction::triggered,this,&MainWindow::timeDate);
    editMenu->addAction(timeDateAction);

    cutAction->setEnabled(false);
    copyAction->setEnabled(false);
    deleteAction->setEnabled(false);
    findAction->setEnabled(false);
    findNextAction->setEnabled(false);

    connect(textEdit,&QTextEdit::copyAvailable,cutAction,&QAction::setEnabled);
    connect(textEdit, &QTextEdit::copyAvailable,copyAction,&QAction::setEnabled);
    connect(textEdit,&QTextEdit::copyAvailable,deleteAction,&QAction::setEnabled);
    connect(textEdit, &QTextEdit::copyAvailable,findAction,&QAction::setEnabled);
    connect(textEdit,&QTextEdit::copyAvailable,findNextAction,&QAction::setEnabled);
}

void MainWindow::createFormatActions(){
    QMenu *formatMenu = menuBar()->addMenu(tr("F&ormat"));
    QAction *wordWrapAction = new QAction(tr("&Word Wrap"),this);
    wordWrapAction->setCheckable(true);
    //set the status tip
    wordWrapAction->setChecked(true);
    connect(wordWrapAction,&QAction::toggled,this,&MainWindow::wordWrap);
    formatMenu->addAction(wordWrapAction);

    QAction *fontAction = new QAction(tr("&Font..."),this);
    fontAction->setStatusTip(tr("Change font settings"));
    connect(fontAction,&QAction::triggered,this,&MainWindow::editFont);
    formatMenu->addAction(fontAction);
}
void MainWindow::createViewActions(){
    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    QAction *statusBarAction = new QAction(tr("&Status Bar"),this);
     statusBarAction->setCheckable(true);
     statusBarAction->setChecked(false);
    connect(statusBarAction,&QAction::toggled,this,&MainWindow::showStatusBar);
    viewMenu->addAction(statusBarAction);

}
void MainWindow::createHelpActions(){
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *helpAction = new QAction(tr("View &Help"),this);
    //set status tip
    connect(helpAction,&QAction::triggered,this,&MainWindow::viewHelp);
    helpMenu->addAction(helpAction);

    QAction *aboutAction = new QAction(tr("&About NotePad--"),this);
    //set status tip
    connect(aboutAction,&QAction::triggered,this,&MainWindow::viewHelp);
    helpMenu->addAction(aboutAction);

}
void MainWindow::createActions(){

    createFileActions();
    createEditActions();
    createFormatActions();
    createViewActions();
    createHelpActions();

}
