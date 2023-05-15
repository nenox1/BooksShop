#include "qdialoggenre.h"
#include "ui_qdialoggenre.h"
#include "dlgnewrecord.h"

QDialogGenre::QDialogGenre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogGenre)
{
    ui->setupUi(this);
    model = new QSqlTableModel;

   refreshTable();

}

QDialogGenre::~QDialogGenre()
{

    delete model;

    delete ui;
}

void QDialogGenre::on_buttonBox_accepted()
{
    accept();
}


void QDialogGenre::on_btnNewRecord_clicked()
{
    DlgNewRecord *dlg= new DlgNewRecord();
    QString genre;
    QString description;
    QMessageBox mb;

    if(dlg->exec() == QDialog::Accepted){

            genre =  dlg->getGenre();
            description = dlg->getDescription();
            try{
                QSqlQuery query;
                query.prepare("INSERT INTO genre (genre, description) "
                              "VALUES ( :genre, :description)");
                query.bindValue(":genre", genre);
                query.bindValue(":description", description);

                if (!query.exec()) {

                    mb.setText(query.lastError().text());
                    mb.exec();
                   return;
                }

            }
            catch(...){

            }
    }

    refreshTable();
    delete dlg;
}


void QDialogGenre::on_btnDeleteRecord_clicked()
{
    QMessageBox msgBox;
    QMessageBox mb;

    msgBox.setWindowTitle("Delete Genre");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.setText(QString("Do you want to delete %1").arg(genre));
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes){

            try{
                QSqlQuery query;
                query.prepare("delete from genre "
                              "where genre = :genre");
                query.bindValue(":genre", genre);
                //query.bindValue(":description", description);

                if (!query.exec()) {

                   mb.setText(query.lastError().text());
                   mb.exec();
                   return;
                }
                 mb.setText(QString("Deleted, Genre: %1").arg(genre));
                 mb.exec();

                refreshTable();
            }
            catch(...){}

    }else {

            mb.setText("Canceled by User");
            mb.exec();
            }


}


void QDialogGenre::on_tableViewGenre_clicked(const QModelIndex &index)
{
    const QVariant &qVariantRow = index.row();
    ID = model->record(index.row()).value("ID").toInt();
    genre = model->record(index.row()).value("Genre").toString();

    if(ID==0){
            ui->btnDeleteRecord->setEnabled(false);
    }
    else{
            ui->btnDeleteRecord->setEnabled(true);
    }

}

void QDialogGenre::refreshTable()
{
    model->setTable("genre");

    try{

                   model->select();
                   //  int salary = model->record(0).value("ID").toInt();
                   //QString Genre = model->record(0).value("Genre").toString();

                   ui->tableViewGenre->setModel(model);
                   ui->tableViewGenre->setColumnWidth(1, 250);
                   ui->tableViewGenre->setColumnWidth(2, 250);
                   ui->tableViewGenre->hideColumn(0); // don't show the ID
                   ui->tableViewGenre->show();


    }
    catch(...){

    }

}

