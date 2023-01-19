#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>

class Game : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentWord READ currentWord CONSTANT)
    Q_PROPERTY(int tryNumber READ tryNumber CONSTANT)
    Q_PROPERTY(int maxNumber READ maxNumber CONSTANT)

    Q_PROPERTY(QString currentTry READ currentTry CONSTANT)
    Q_PROPERTY(QStringList wordTries READ wordTries CONSTANT)

public:
    explicit Game(QObject *parent = nullptr);

public slots:
    QString currentWord() const         { return _currentWord; }
    int tryNumber() const               { return _tryNumber; }
    int maxNumber() const               { return _maxNumber; }
    QString currentTry() const          { return _currentTry; }
    QStringList wordTries() const       { return _wordTries; }

    void generateNewWord();
    void clear();
    void turnOff();

    bool checkIfWordExist(QString);
    bool checkIfWordCorrect(QString);

signals:
    void shutdownNow(int returnCode);

private:
    void shutdown(int returnCode);

private:
    QString _currentWord;
    int _tryNumber;
    int _maxNumber;

    QString _currentTry;
    QStringList _wordTries;
};

#endif // GAME_H
