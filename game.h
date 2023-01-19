#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>

class Game : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentWord READ currentWord CONSTANT)
    Q_PROPERTY(int currentTry READ currentTry CONSTANT)

public:
    explicit Game(QObject *parent = nullptr);

public slots:
    QString currentWord() const { return _currentWord; }
    int currentTry() const      { return _currentTry; }

    void generateNewWord();
    void clear();
    bool checkIfWordExist(QString);
    bool checkIfWordCorrect(QString);

private:
    QString _currentWord;
    int _currentTry;
    QList<QString> wordTries;


};

#endif // GAME_H
