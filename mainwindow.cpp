#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    HistoryIndex = 0;

    model = new QDirModel(this);
    model->setReadOnly(true);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);

    ui->treeView->setModel(model);

    QModelIndex index = model->index(QDir::currentPath());
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);
    ui->treeView->setColumnHidden(1,true);
    ui->treeView->setColumnHidden(2,true);
    ui->treeView->setColumnHidden(3,true);
    ui->treeView->header()->hide();

    ui->treeView->verticalScrollBar()->setStyleSheet(
        "background-color: #EAF5FF;"
        "alternate-background-color: #D5EAFF;"
        "border: 1px solid #000000"
    );

    ui->treeView->horizontalScrollBar()->setStyleSheet(
                "background-color: #EAF5FF;"
                "alternate-background-color: #D5EAFF;"
                "border: 1px solid #000000"
            );

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    HistoryList << index;
    HistoryIndex = HistoryList.indexOf(index);
    CurrentFile.FileName = index.data(Qt::DisplayRole).toString();
    CurrentFile.Path = QFileInfo(model->filePath(index)).absolutePath();
    CurrentFile.AbsoluteFileName = model->filePath(index);
}

void MainWindow::on_btnInfo_clicked() {
    QString html;
    html = "<p><b style=\"font-size: 14pt\">tafm</b> 0.1<br>\n";
    html.append("&copy;2017 <a href=\"http://www.matthewhipkin.co.uk\" style=\"color: #FF0000\">Matthew Hipkin</a><br>\n");
    html.append("<p>A tiny file manager</p>");
    //html.append("<p>Follow me on twitter <a href=\"https://twitter.com/hippy2094\" style=\"color: #FF0000\">@hippy2094</a></p>");
    QMessageBox::about(this,"About tafm",html);
}

void MainWindow::on_btnBack_clicked() {
    if(HistoryIndex < 1) return;
    HistoryIndex--;
    QModelIndex LastIndex = HistoryList.at(HistoryIndex);
    ui->treeView->expand(LastIndex);
    ui->treeView->scrollTo(LastIndex);
    ui->treeView->setCurrentIndex(LastIndex);
}

void MainWindow::on_btnForward_clicked() {
    if((HistoryIndex+1) > HistoryList.count()) return;
    HistoryIndex++;
    QModelIndex LastIndex = HistoryList.at(HistoryIndex);
    ui->treeView->expand(LastIndex);
    ui->treeView->scrollTo(LastIndex);
    ui->treeView->setCurrentIndex(LastIndex);
}

void MainWindow::on_btnCut_clicked() {
    FileMode = mCutting;
    SourceFile = CurrentFile;
}

void MainWindow::on_btnCopy_clicked() {
    FileMode = mCopying;
    SourceFile = CurrentFile;
}

void MainWindow::on_btnPaste_clicked() {
    //QFile::copy();
    QString t;
    if(FileMode == mCutting) t = "Are you sure you want to move this file?";
    else t = "Are you sure you want to copy this file?";
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", t, QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {

    }
    else {
        FileMode = mNone;
        SourceFile = EmptyFile;
    }
}

void MainWindow::on_btnDelete_clicked() {
    //QFile::remove();
}

void MainWindow::on_btnRename_clicked() {
    //QFile::rename();
}
