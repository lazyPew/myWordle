#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>

#include "wordsmodel.h"

class Game : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentWord READ currentWord CONSTANT)
    Q_PROPERTY(int tryNumber READ tryNumber CONSTANT)
    Q_PROPERTY(int maxNumber READ maxNumber CONSTANT)

    Q_PROPERTY(QString currentTry READ currentTry CONSTANT)
    Q_PROPERTY(QStringList wordTries READ wordTries CONSTANT)
    Q_PROPERTY(WordsModel* wordsModel READ wordsModel CONSTANT)

public:
    explicit Game(QObject *parent = nullptr);

public slots:
    QString currentWord() const     { return _currentWord; }
    int tryNumber() const           { return _tryNumber; }
    int maxNumber() const           { return _maxNumber; }
    QString currentTry() const      { return _currentTry; }
    QStringList wordTries() const   { return _wordTries; }
    WordsModel* wordsModel() const  { return _wordsModel; }

    void generateNewWord();
    void clear();
    void turnOff();

    bool checkIfWordExist(QString);
    bool checkIfWordCorrect(QString);

signals:
    void shutdownNow(int returnCode);

private:
    void registerQmlTypes();
    void shutdown(int returnCode);

private:
    QString _currentWord;
    int _tryNumber;
    int _maxNumber;

    QString _currentTry;
    QStringList _wordTries;

    WordsModel* _wordsModel;
};

#endif // GAME_H
