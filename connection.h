
#ifndef CONNECTION_H
#define CONNECTION_H



static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("Driver={SQL Server Native Client 11.0};Server=DESKTOP-E7SGDD1\\LEVEL2;Database=BOOKSHOP;Trusted_Connection=Yes;"));

    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                          "This example needs SQLite support. Please read "
                                          "the Qt SQL driver documentation for information how "
                                          "to build it.\n\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }



    return true;
}

//! [0]


#endif // CONNECTION_H
