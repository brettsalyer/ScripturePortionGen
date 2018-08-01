#include "generation.h"

generation::generation(){

}
generation::generation(QList<QString> books, QList<QString> headers, QString ft){
    ids = books;
    bookHeaders = headers;
    fileType = ft;
}

generation::~generation(){
}

QList<QString> generation::getBooks(){
    return BOOKS;
}

void generation::loadSelected(QString id, QString header){
    QFile inFile(INPUT_FILE_PATH);
    QFile outFile(OUTPUT_FILE_PATH);
    QString reference;
    int counter = 0;
    int chapter = 1;
    bool keepGoing = true;

    qDebug() << "BSB File found: " << inFile.exists();

    if (inFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&inFile);

        while(!in.atEnd() && keepGoing){

            QString line = in.readLine();
            QList<QString> elements = line.split("\t");

            if(elements.size() >= 1){
                reference = elements[0];
            }else{
                qDebug() << elements.size();
                qDebug() << line << counter;
                reference = "UNIMPORTANT";
            }

            if(reference == id){
                qDebug() << id << " Found!";

                if(outFile.open(QIODevice::ReadWrite | QIODevice::Append)){
                QTextStream out(&outFile);
                out << "<!DOCTYPE html>";
                out << "<br><h><center><b><font size ='12.5'>" << header << " " << chapter << "</font></b></center></h><br><br>";
                if(doTraditional){
                    minimizeReference(line);
                }
                out << line << "<br>";

                while(keepGoing){
                    line = in.readLine();
                    elements = line.split("\t");

                    if(reachedNext(elements)){
                        keepGoing = false;
                    }else{
                        if(reachedNextChapter(elements, chapter)){
                            chapter++;
                            out << "<br><h><center><b><font size ='12.5'>" << header << " " << chapter << "</font></b></center></h><br><br>";

                        }
                        if(doTraditional){
                            minimizeReference(line);
                        }
                        out << line << "<br>";

                    }

                }

                }


            }
            counter++;
        }
    }
    reference.clear();
    inFile.close();
    outFile.close();
    }

//Function that takes in the currently read line and chops off the book title and chapter, leaving only the verse number
void generation::minimizeReference(QString &currentLine){
    QList<QString> splitLine = currentLine.split(":");
    splitLine.removeFirst();
    currentLine = splitLine[0];
    splitLine = currentLine.split("\t");
    splitLine.insert(1, "&nbsp");
    currentLine = splitLine.join(" ");

}

bool generation::reachedNext(QList<QString> elements){
    QList<QString> reference = elements[0].split(" ");
    if(reference.contains("1:1")){
        return true;
    }else{
        return false;
    }

}

bool generation::reachedNextChapter(QList<QString> elements, int currentChapter){
    QString bookAndRef = elements.join(" ");
    QList<QString> bySpaces = bookAndRef.split(" ");
    QList<QString> reference;

    bool reachedNextChapter = false;

    for (int i = 0; i < bySpaces.size(); i++){
        if (bySpaces[i].contains(":")){
            reference = bySpaces[i].split(":");
            if(reference[0].toInt() == currentChapter + 1){
                reachedNextChapter = true;
            }

        }

    }

    return reachedNextChapter;
}

void generation::setBooks(QString book){
    starting = book;

    if(starting == BOOKS[0]){
        ids.clear();
        bookHeaders.clear();
        ids.append(LUKE);
        bookHeaders.append(LUKE_H);
    }
    if(starting == BOOKS[1]){
        ids.clear();
        bookHeaders.clear();
        ids.append(CORINTHIAN1);
        ids.append(CORINTHIAN2);
        bookHeaders.append(CORINTHIAN1_H);
        bookHeaders.append(CORINTHIAN2_H);

    }
    if(starting == BOOKS[2]){
        ids.clear();
        bookHeaders.clear();

        ids.append(JOHN);
        bookHeaders.append(JOHN_H);
    }
    if(starting == BOOKS[3]){
        ids.clear();
        bookHeaders.clear();

        ids.append(HEBREWS);
        ids.append(PETER1);
        ids.append(PETER2);
        bookHeaders.append(HEBREWS_H);
        bookHeaders.append(PETER1_H);
        bookHeaders.append(PETER2_H);
    }
    if(starting == BOOKS[4]){
        ids.clear();
        bookHeaders.clear();

        ids.append(MATTHEW);
        bookHeaders.append(MATTHEW_H);
    }
    if(starting == BOOKS[5]){
        ids.clear();
        bookHeaders.clear();

        ids.append(ROMANS);
        ids.append(JAMES);
        bookHeaders.append(ROMANS_H);
        bookHeaders.append(JAMES_H);
    }
    if(starting == BOOKS[6]){
        ids.clear();
        bookHeaders.clear();

        ids.append(ACTS);
        bookHeaders.append(ACTS_H);
    }
    if(starting == BOOKS[7]){
        ids.clear();
        bookHeaders.clear();

        ids.append(GALATIONS);
        ids.append(EPHESIANS);
        ids.append(PHILLIPIANS);
        ids.append(COLOSSIANS);
        ids.append(PHILEMON);
        bookHeaders.append(GALATIONS_H);
        bookHeaders.append(EPHESIANS_H);
        bookHeaders.append(PHILLIPIANS_H);
        bookHeaders.append(COLOSSIANS_H);
        bookHeaders.append(PHILEMON_H);
    }
    //Debug
    qDebug() << starting;

    for (int i =0; i < ids.size(); i++){
        qDebug() << ids[i];
    }
}

QList<QString> generation::getID(){
    return ids;
}

QList<QString> generation::getFileTypes(){
    return FILE_TYPES;
}

QList<QString> generation::getHeaders(){
    return bookHeaders;
}

void generation::setFilePath(QString filepath){
    OUTPUT_FILE_PATH = filepath;
}

void generation::setTraditional(bool value){
    doTraditional = value;
}

bool generation::getTraditional(){
    return doTraditional;
}
