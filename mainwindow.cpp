
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialoggenre.h"
#include <stdlib.h>
#include<dialogbuybook.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!createConnection()){
        QMessageBox mb;

        mb.setText("Not connected to DB");

        mb.exec();
        }

    model = new QSqlTableModel;

    refreshTable();
}

MainWindow::~MainWindow()
{

    delete model;

    delete ui;
}

void MainWindow::on_BtnDialogGenre_clicked()
{

    QDialogGenre *dialog = new QDialogGenre();
    QMessageBox mb;

    if(dialog->exec()){
          delete dialog;
    }


}

void MainWindow::refreshTable()
{
    model->setTable("books");

    try{
        model->setQuery("SELECT a.id, a.author, a.title, B.Genre as genre, a.price, a.stock FROM books A, GENRE B where A.genreId = B.ID");

        ui->tableViewBooks->setModel(model);
        ui->tableViewBooks->setColumnWidth(1, 250);
        ui->tableViewBooks->setColumnWidth(2, 250);
        ui->tableViewBooks->hideColumn(0); // don't show the ID
        ui->tableViewBooks->show();
    }
    catch(...){

    }

}


void MainWindow::on_btnNewBook_clicked()
{
    DlgNewBook newBook;
    newBook.exec();

    refreshTable();

}


void MainWindow::on_tableViewBooks_clicked(const QModelIndex &index)
{
    const QVariant &qVariantRow = index.row();
    id = model->record(index.row()).value("ID").toInt();
    author = model->record(index.row()).value("Author").toString();
    bookTitle = model->record(index.row()).value("Title").toString();
    price = model->record(index.row()).value("price").toFloat();
    stock = model->record(index.row()).value("stock").toInt();

    if(id==0){
            ui->btnDeleteBook->setEnabled(false);
            ui->btnBuyBook->setEnabled(false);
    }
    else{
            ui->btnDeleteBook->setEnabled(true);
            ui->btnBuyBook->setEnabled(true);
    }
}


void MainWindow::on_btnDeleteBook_clicked()
{
    QMessageBox msgBox;
    QMessageBox mb;

    msgBox.setWindowTitle("Delete Book");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.setText(QString("Do you want to delete %1").arg(bookTitle));
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes){

            try{
                QSqlQuery query;
                query.prepare("delete from books "
                              "where title = :bookTitle");
                query.bindValue(":bookTitle", bookTitle);

                if (!query.exec()) {

                    mb.setText(query.lastError().text());
                    mb.exec();
                    return;
                }
                mb.setText(QString("Deleted, Titel: %1").arg(bookTitle));
                mb.exec();

                refreshTable();
            }
            catch(...){}

    }else {

            mb.setText("Canceled by User");
            mb.exec();
    }
}


void MainWindow::on_btnBuyBook_clicked()
{
   DialogBuyBook dlgBuyBook(author,bookTitle, price, stock); //= new DialogBuyBook;
    dlgBuyBook.exec();

    refreshTable();

}

