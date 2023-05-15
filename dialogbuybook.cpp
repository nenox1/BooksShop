#include "dialogbuybook.h"
#include "ui_dialogbuybook.h"

DialogBuyBook::DialogBuyBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBuyBook)
{
    ui->setupUi(this);
}

DialogBuyBook::DialogBuyBook(QString author, QString title, float price, int stock, QWidget *parent):QDialog(parent), ui(new Ui::DialogBuyBook)
{
     ui->setupUi(this);

    ui->txtAuthor->setText(author);
    ui->txtTitle->setText(title);
    ui->txtPrice->setText(QString::number(price));
    ui->txtStock->setText(QString::number(stock));

    dAuthor = author;
    dTitle = title;;
    dPrice =  price;
    dStock=  stock;
    ui->txtQuantity->setFocus();

}

DialogBuyBook::~DialogBuyBook()
{
     delete ui;
}

void DialogBuyBook::setAuthor(QString &author)
{

     ui->txtAuthor->setText( author);

}

void DialogBuyBook::on_btnOk_clicked()
{
     QMessageBox mb;

     if(sumStock <= 0){
         mb.setText("Stock is 0 or lower than 0, unable to buy book.");
         mb.exec();
         return;
     }
     else{
         float calculatedCheck = 0;
         int stock = ui->txtQuantity->text().toInt();
         calculatedCheck = stock * dPrice;

         QSqlQuery query;
         QString test = QString( "update books set stock = %1 where title = '%2'").arg(sumStock).arg(dTitle);

         query.prepare(test);

         if (!query.exec()) {

             mb.setText(query.lastError().text());
             mb.exec();
             return;
         }

         mb.setText(QString("You buy a book, Titel: %1 Quantity: %2, Price: %3" ).arg(dTitle).arg(stock).arg(calculatedCheck));
         mb.exec();

     }

    accept();
}


void DialogBuyBook::on_btnCancel_clicked()
{
    close();
}


void DialogBuyBook::on_txtQuantity_textChanged(const QString &arg1)
{
    QMessageBox mb;

    int stock = ui->txtQuantity->text().toInt();
    sumStock = dStock - stock;

    ui->lbQuantitySum->setText(QString("Stock left: %1").arg(QString::number(sumStock)));
}

