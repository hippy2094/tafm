#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

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

void MainWindow::on_btnInfo_clicked() {
    QString html;
    html = "<p><b style=\"font-size: 14pt\">tafm</b> 0.1<br>\n";
    html.append("&copy;2017 <a href=\"http://www.matthewhipkin.co.uk\" style=\"color: #FF0000\">Matthew Hipkin</a><br>\n");   
    html.append("<p>A tiny file manager</p>");
    //html.append("<p>Follow me on twitter <a href=\"http://twitter.com/hippy2094\" style=\"color: #FF0000\">@hippy2094</a></p>");
    QMessageBox::about(this,"About tafm",html);
}
