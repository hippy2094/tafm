#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QScrollBar>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

enum TCurrentMode { mNone, mCutting, mCopying };

struct TSelectedFile {
    QString FileName;
    QString Path;
    QString AbsoluteFileName;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnInfo_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_btnBack_clicked();

    void on_btnForward_clicked();

private:
    Ui::MainWindow *ui;
    QDirModel *model;    
    QList<QModelIndex> HistoryList;
    int HistoryIndex;
    TCurrentMode FileMode;
    TSelectedFile CurrentFile;

};

#endif // MAINWINDOW_H
