#include "dlgnewbook.h"
#include "ui_dlgnewbook.h"

DlgNewBook::DlgNewBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewBook)
{
    ui->setupUi(this);

    populateComboGenre();

}

DlgNewBook::~DlgNewBook()
{
    delete ui;
}

void DlgNewBook::populateComboGenre()
{
    QSqlQuery query;
    query.prepare("SELECT genre FROM genre");
    query.exec();

    while(query.next()){
        ui->cmbGenre->addItem(query.value("Genre").toString());
    }

}

void DlgNewBook::on_btnCancel_clicked()
{
    close();
}


void DlgNewBook::on_btnOK_clicked()
{
    if(!ui->lineAuthor->text().size()>0 || !ui->lineTitle->text().size()>0 || !ui->lineStock->text().size()>0 || !ui->linePrice->text().size()>0){
        QMessageBox mb;
        mb.setText("Plese enter author, title, stock and price!");
        mb.exec();
        return;
    }


    QMessageBox mb;
    try{
        QSqlQuery query;
        query.prepare("INSERT INTO books (author, title, genreID, price, stock) "
                      "VALUES ( :author, :title, :genreID, :price, :stock)");
        query.bindValue(":author", ui->lineAuthor->text());
        query.bindValue(":title", ui->lineTitle->text());
        query.bindValue(":genreID", genreId);
        query.bindValue(":price", ui->linePrice->text().toFloat());
        query.bindValue(":stock", ui->lineStock->text().toInt());

        if (!query.exec()) {

            mb.setText(query.lastError().text());
            mb.exec();
            return;
        }

    }
    catch(...){

    }


    accept();
}


void DlgNewBook::on_cmbGenre_currentIndexChanged(int index)
{

    QSqlQuery query;
    QString test = QString( "select id from genre where genre = '%1'").arg(ui->cmbGenre->currentText());

    query.prepare(test);
    query.exec();

    query.first();

    genreId = query.value(0).toInt();


}

