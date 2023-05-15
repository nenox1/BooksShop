#ifndef DIALOGBUYBOOK_H
#define DIALOGBUYBOOK_H

#include <QDialog>
#include<QMessageBox>
#include <QtSql>

namespace Ui {
class DialogBuyBook;
}

class DialogBuyBook : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBuyBook(QWidget *parent = nullptr);
    explicit DialogBuyBook(QString author, QString title, float price, int stock, QWidget *parent = nullptr);



    ~DialogBuyBook();
    void setAuthor(QString &author);

private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void on_txtQuantity_textChanged(const QString &arg1);

private:
    Ui::DialogBuyBook *ui;
    QString dAuthor;
    QString dTitle;
    float dPrice;
    int dStock;
    int sumStock = 0;
};

#endif // DIALOGBUYBOOK_H
