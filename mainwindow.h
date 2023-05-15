
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlTableModel>
#include<QSqlRecord>
#include<connection.h>
#include "dlgnewbook.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QSqlTableModel *model;

    void refreshTable();


private slots:

    void on_BtnDialogGenre_clicked();

    void on_btnNewBook_clicked();

    void on_tableViewBooks_clicked(const QModelIndex &index);

    void on_btnDeleteBook_clicked();

    void on_btnBuyBook_clicked();

private:
    Ui::MainWindow *ui;
    int id = 0;
    QString author;
    QString bookTitle;
    float price;
    int stock;
};

#endif // MAINWINDOW_H
