#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QScrollBar>
#include <QMessageBox>
#include <QDebug>
#include <QFile>

namespace Ui {
class MainWindow;
}

enum TCurrentMode { mNone, mCutting, mCopying };

struct TSelectedFile {
    QString FileName;
    QString Path;
    QString AbsoluteFileName;
};

static const struct TSelectedFile EmptyFile;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_btnInfo_clicked();
    void on_btnBack_clicked();
    void on_btnForward_clicked();
    void on_btnCut_clicked();
    void on_btnCopy_clicked();
    void on_btnPaste_clicked();
    void on_btnDelete_clicked();
    void on_btnRename_clicked();

private:
    Ui::MainWindow *ui;
    QDirModel *model;    
    QList<QModelIndex> HistoryList;
    int HistoryIndex;
    TCurrentMode FileMode;
    TSelectedFile CurrentFile;
    TSelectedFile SourceFile;

};

#endif // MAINWINDOW_H
