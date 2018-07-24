#ifndef GENERATION_H
#define GENERATION_H

#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QObject>

class generation
{
public:
    //Default and Generation Constructors
    generation();
    ~generation();
    generation(QList<QString>, QList<QString>, QString);


    QList<QString> getBooks();
    void setBooks(QString);
    bool reachedNext(QList<QString>);
    bool reachedNextChapter(QList<QString>, int);

    void loadSelected(QString, QString);
    QList<QString> getID();
    QList<QString> getFileTypes();
    QList<QString> getHeaders();
    void setFilePath(QString filepath);



private:
    //Constant lists that hold comboBox values
    const QList<QString> BOOKS = {"Luke", "1 & 2 Corinthians", "John", "Hebrews, 1 & 2 Peter","Matthew",
                                  "Romans & James", "Acts", "Galations, Ephesians, Phillipians, Colossians, Philemon"};
    const QList<QString> FILE_TYPES = {".HTML", ".PDF", ".TXT"};

    //Constant IDs for searching for new books
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
    const QString GALATIONS = {"Galatians 1:1"};
    const QString EPHESIANS = {"Ephesians 1:1"};
    const QString PHILLIPIANS = {"Philippians 1:1"};
    const QString COLOSSIANS = {"Colossians 1:1"};
    const QString PHILEMON = {"Philemon 1:1"};

    //Headers to be used at the top of every new chapter. i.e, LUKE_H + 1 = Luke 1
    const QString LUKE_H = {"Luke"};
    const QString CORINTHIAN1_H = {"1 Corinthians"};
    const QString CORINTHIAN2_H = {"2 Corinthians"};
    const QString JOHN_H = {"John"};
    const QString PETER1_H = {"1 Peter"};
    const QString PETER2_H = {"2 Peter"};
    const QString MATTHEW_H = {"Matthew"};
    const QString JAMES_H = {"James"};
    const QString ACTS_H = {"Acts"};
    const QString ROMANS_H = {"Romans"};
    const QString HEBREWS_H = {"Hebrews"};
    const QString GALATIONS_H = {"Galations"};
    const QString EPHESIANS_H = {"Ephesians"};
    const QString PHILLIPIANS_H = {"Philippians"};
    const QString COLOSSIANS_H = {"Colossians"};
    const QString PHILEMON_H = {"Philemon"};

    //A list to store all headers to be used for portion generation (useful for multi-book years)
    QList<QString> bookHeaders;

    //Contains IDs for selected portions
    QList<QString> ids;

    //File Type selected
    QString fileType;

    //Input output destinations (TODO: Make cross-platform)
    QString INPUT_FILE_PATH = "bsb.txt";
    QString OUTPUT_FILE_PATH = "Generated.html";


    //Boolean value to handle if verse-by-verse, if boldUnique
    bool doVBV;
    bool doUnique;
    QString starting;


};


#endif // GENERATION_H
