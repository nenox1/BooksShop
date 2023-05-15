#ifndef DLGNEWRECORD_H
#define DLGNEWRECORD_H

#include <QDialog>
#include<QLineEdit>
#include <QMessageBox>
#include<mainwindow.h>


namespace Ui {
class DlgNewRecord;
}

class DlgNewRecord : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewRecord(QWidget *parent = nullptr);
    ~DlgNewRecord();

    QString getGenre();
    QString getDescription();


private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void on_txtGenre_textChanged(const QString &arg1);

private:
    Ui::DlgNewRecord *ui;
    QLineEdit lineGenre;
    QLineEdit lineDescription;

    QString genre;
    QString description;
};

#endif // DLGNEWRECORD_H
