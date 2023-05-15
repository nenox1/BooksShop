#ifndef DLGNEWBOOK_H
#define DLGNEWBOOK_H

#include <QDialog>
#include<QtSql>
#include <QMessageBox>


namespace Ui {
class DlgNewBook;
}

class DlgNewBook : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewBook(QWidget *parent = nullptr);
    ~DlgNewBook();

    void populateComboGenre();
    int genreId = 0;

private slots:
    void on_btnCancel_clicked();

    void on_btnOK_clicked();

    void on_cmbGenre_currentIndexChanged(int index);



private:
    Ui::DlgNewBook *ui;
};

#endif // DLGNEWBOOK_H
