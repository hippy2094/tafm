#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QScrollBar>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnInfo_clicked();

private:
    Ui::MainWindow *ui;
    QDirModel *model;
};

#endif // MAINWINDOW_H
