#include "game.h"
#include "QRandomGenerator"

Game::Game(QObject *parent)
    : QObject(parent)
    , _tryNumber(0)
    , _maxNumber(6)
    , _wordsModel{nullptr}
{
    generateNewWord();

    connect(this, &Game::shutdownNow,
            this, &Game::shutdown, Qt::QueuedConnection);
    registerQmlTypes();
}

void Game::generateNewWord()
{
    _wordTries = QStringList{};
    QFile file(":/words.txt");
    if(file.exists()){
        // TODO make warning that program needs file with words
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

    QString word = wordVect[QRandomGenerator::global()->bounded(wordVect.size())];
    _wordsModel = new WordsModel(word);

    for (int i = 0; i < maxNumber(); i++){
        _wordTries.append(wordVect[QRandomGenerator::global()->bounded(wordVect.size())]);
//        qDebug() << wordTries();
//        qDebug() << word;
    }
    for(auto s: _wordTries){
        _wordsModel->guessWord(s);
    }
}

void Game::clear(){

}

bool Game::checkIfWordExist(QString){

}

bool Game::checkIfWordCorrect(QString){

}

void Game::registerQmlTypes()
{
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<WordClass>(
                    "DataModels",
                    1, 0,
                    "WordClass", "NOPE"
                    );
        registered = true;
    }
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
