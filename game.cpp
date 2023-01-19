#include "game.h"
#include "QRandomGenerator"

Game::Game(QObject *parent)
    : QObject(parent)
    , _tryNumber(0)
    , _maxNumber(6)
    , _wordTries{QStringList{}}
{
    generateNewWord();

    connect(this, &Game::shutdownNow,
            this, &Game::shutdown, Qt::QueuedConnection);
}

void Game::generateNewWord()
{
    QFile file(":/words.txt");
    if(file.exists()){
        // TODO crete warning that program needs file with words
    }
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "error opening file";
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QVector<QString> wordVect;

    while (!in.atEnd()) {
        QString line = in.readLine();
        wordVect << line;
    }

    for (int i = 0; i < maxNumber(); i++){
//        QString word = wordVect[QRandomGenerator::global()->bounded(wordVect.size())];
        _wordTries.append(wordVect[QRandomGenerator::global()->bounded(wordVect.size())]);
        qDebug() << wordTries();
    }
}

void Game::clear(){

}

bool Game::checkIfWordExist(QString){

}

bool Game::checkIfWordCorrect(QString){

}

void Game::shutdown(int returnCode){
    qDebug() << "shutdown";
    QString command("kill ");
    command.append(QString::number(QCoreApplication::applicationPid()));
    system(qPrintable(command));
    QCoreApplication::exit(returnCode);
}


void Game::turnOff(){
    int exitCode = 201;
    emit shutdownNow(exitCode);
}
