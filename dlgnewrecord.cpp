#include "dlgnewrecord.h"
#include "ui_dlgnewrecord.h"

DlgNewRecord::DlgNewRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewRecord)
{
    ui->setupUi(this);

}

DlgNewRecord::~DlgNewRecord()
{
    delete ui;
}

void DlgNewRecord::on_btnOk_clicked()
{

    genre = ui->txtGenre->text();
    description = ui->txtDescription->text();

    accept();
}


void DlgNewRecord::on_btnCancel_clicked()
{
    close();
}


void DlgNewRecord::on_txtGenre_textChanged(const QString &arg1)
{
     if(!arg1.isEmpty()){
        ui->btnOk->setEnabled(true);
     }
     else{
        ui->btnOk->setEnabled(false);

     }
}

QString DlgNewRecord::getGenre()
{
     return genre;
}

QString DlgNewRecord::getDescription()
{
     return description;
}


