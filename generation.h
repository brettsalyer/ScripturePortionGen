#ifndef GENERATION_H
#define GENERATION_H

#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class generation
{
public:
    generation();
    ~generation();
    QList<QString> getBooks();
    bool reachedNext(QList<QString>);
    void setStarting(QString);
    void loadSelected(QString);
    QList<QString> getID();


private:
    const QList<QString> BOOKS = {"Luke", "1 & 2 Corinthians", "John", "Hebrews, 1 & 2 Peter","Matthew",
                                  "Romans & James", "Acts", "Galations, Ephesians, Phillipians, Colossians, Philemon"};
    const QString LUKE = {"Luke 1:1"};
    const QString CORINTHIAN1 = {"1 Corinthians 1:1"};
    const QString CORINTHIAN2 = {"2 Corinthians 1:1"};
    const QString JOHN = {"John 1:1"};
    const QString PETER1 = {"1 Peter 1:1"};
    const QString PETER2 = {"2 Peter 1:1"};
    const QString MATTHEW = {"Matthew 1:1"};
    const QString JAMES = {"James 1:1"};
    const QString ACTS = {"Acts 1:1"};
    const QString ROMANS = {"Romans 1:1"};
    const QString HEBREWS = {"Hebrews 1:1"};
    const QString GALATIONS = {"Galations 1:1"};
    const QString EPHESIANS = {"Ephesians 1:1"};
    const QString PHILLIPIANS = {"Phillipians 1:1"};
    const QString COLOSSIANS = {"Colossians 1:1"};
    const QString PHILEMON = {"Philemon 1:1"};

    QString INPUT_FILE_PATH = "D:/brett/Documents/PortionGen/bsb.txt";
    QString OUTPUT_FILE_PATH = "D:/brett/Documents/PortionGen/Generated.txt";



    bool doVBV;
    bool doUnique;
    QString starting;
    //Contains IDs for selected portions
    QList<QString> ids;

};


#endif // GENERATION_H
