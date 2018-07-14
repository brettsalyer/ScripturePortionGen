#include "generation.h"

generation::generation(){    
}

generation::~generation(){
}

QList<QString> generation::getBooks(){
    return BOOKS;
}

void generation::loadSelected(QString id){
    QFile inFile(INPUT_FILE_PATH);
    QFile outFile(OUTPUT_FILE_PATH);
    QString reference;
    int counter = 0;
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
                out << line << '\n';



                while(keepGoing){
                    line = in.readLine();
                    elements = line.split("\t");

                    if(reachedNext(elements)){
                        keepGoing = false;
                    }else{
                        out << line << '\n';

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


bool generation::reachedNext(QList<QString> elements){
    QList<QString> reference = elements[0].split(" ");
    if(reference.contains("1:1")){
        return true;
    }else{
        return false;
    }

}

void generation::setStarting(QString book){
    starting = book;

    if(starting == BOOKS[0]){
        ids.clear();
        ids.append(LUKE);
    }
    if(starting == BOOKS[1]){
        ids.clear();
        ids.append(CORINTHIAN1);
        ids.append(CORINTHIAN2);
    }
    if(starting == BOOKS[2]){
        ids.clear();
        ids.append(JOHN);
    }
    if(starting == BOOKS[3]){
        ids.clear();
        ids.append(HEBREWS);
        ids.append(PETER1);
        ids.append(PETER2);
    }
    if(starting == BOOKS[4]){
        ids.clear();
        ids.append(MATTHEW);
    }
    if(starting == BOOKS[5]){
        ids.clear();
        ids.append(ROMANS);
        ids.append(JAMES);
    }
    if(starting == BOOKS[6]){
        ids.clear();
        ids.append(ACTS);
    }
    if(starting == BOOKS[7]){
        ids.clear();
        ids.append(GALATIONS);
        ids.append(EPHESIANS);
        ids.append(PHILLIPIANS);
        ids.append(COLOSSIANS);
        ids.append(PHILEMON);
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
