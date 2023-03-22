#include "wordsmodel.h"
#include <QFile>
#include <QDebug>

WordClass::WordClass(QString str)
    : _str{str}
    , _correct{false}
{}

WordClass::WordClass(QString str, QString correctWord)
    : _str{str}
    , _correct{false}
{
    checkLetters(correctWord);
}

bool WordClass::checkLetters(QString correctWord)
{
    // TODO think about words with same letters
    qDebug() << _str;
    for(int i = 0; i < _str.length(); i++){
        if(correctWord.at(i) == _str.at(i)){
            _lettersCorrectness.append(WordClass::Correctness::LetterCorrect);
            _correct = true;
        }
        else if(correctWord.contains(_str.at(i))){
            _lettersCorrectness.append(WordClass::Correctness::LetterInAnotherPlace);
        }
        else{
            _lettersCorrectness.append(WordClass::Correctness::LetterNotInWord);
        }
    }
    return _correct;
}


WordsModel::WordsModel(const QString wordToGuess, QObject *parent)
    : QAbstractListModel(parent)
    , _wordToGuess { wordToGuess }
    , _numberOfTries{0}
{

}

void WordsModel::guessWord(QString newWord)
{
    if(!checkIfWordExists(newWord)){
        emit wordDoesNotExist();
        return;
    }
    _numberOfTries++;
    WordClass* word = new WordClass(newWord);
    word->checkLetters(_wordToGuess);
    _wordTries.append(word);
    qDebug() << _wordToGuess << " "<< word->str();
    qDebug() << word->lettersCorrectness();
}

bool WordsModel::checkLetters(const QString correctWord)
{

}

bool WordsModel::checkIfWordExists(const QString str)
{
    QFile file(":/words.txt");
    if(file.exists()){
        // TODO make warning that program needs file with words
    }
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "error opening file";
        return false;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QStringList wordVect;

    while (!in.atEnd()) {
        QString line = in.readLine();
        wordVect << line;
    }
    return wordVect.contains(str, Qt::CaseInsensitive);
}


int WordsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _wordTries.size();
}

QVariant WordsModel::data(const QModelIndex &index, int role) const
{
    auto const row = index.row();

    switch (role) {
    case static_cast<int>(Roles::WordRole):
        return _wordTries.at(row)->str();
    case static_cast<int>(Roles::CorrectRole):
        return _wordTries.at(row)->correct();
    case static_cast<int>(Roles::LettersRole):
        return QVariant::fromValue(_wordTries.at(row)->lettersCorrectness());
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> WordsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[static_cast<int>(Roles::WordRole)] = "wordRole";
    roles[static_cast<int>(Roles::CorrectRole)] = "correctRole";
    roles[static_cast<int>(Roles::LettersRole)] = "lettersRole";
    return roles;
}

int WordsModel::numberOfTries() const           { return _numberOfTries; }
WordClass *WordsModel::wordAt(int index) const  { return _wordTries.at(index); }
QList<WordClass *> WordsModel::wordTries() const{ return _wordTries; }
