#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

public slots:
    void generateNewWord();
//signals:
private:
    QString _currentWord;
    int currentTry;
    QList<QString> wordTries;


};

#endif // GAME_H
