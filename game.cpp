#include "game.h"
#include "QRandomGenerator"

Game::Game(QObject *parent)
    : QObject(parent)

{
    generateNewWord();
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
    QRandomGenerator gen;
    for (int i = 0; i < 10; i++){
        QString word = wordVect[gen.bounded(wordVect.size())];
        qDebug() << word;
    }
}
