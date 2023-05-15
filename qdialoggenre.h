#ifndef QDIALOGGENRE_H
#define QDIALOGGENRE_H

#include <QDialog>
#include<QSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlTableModel>
#include<QSqlRecord>
#include<QSqlError>
#include<QModelIndex>
#include<mainwindow.h>

namespace Ui {
class QDialogGenre;
}

class QDialogGenre : public QDialog
{
    Q_OBJECT

public:
    explicit QDialogGenre(QWidget *parent = nullptr);
    ~QDialogGenre();

    QSqlTableModel *model;


private slots:
    void on_buttonBox_accepted();

    void on_btnNewRecord_clicked();

    void on_btnDeleteRecord_clicked();

    void on_tableViewGenre_clicked(const QModelIndex &index);

    void refreshTable();

private:
    Ui::QDialogGenre *ui;

    int ID;
    QString genre;

};


#endif // QDIALOGGENRE_H
