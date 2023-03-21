#ifndef WORDSMODEL_H
#define WORDSMODEL_H

#include <QObject>
#include <QAbstractListModel>


//struct LetterCorrect{
//    char l;
//    Correctnes c;
//};

class WordClass : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString str READ str CONSTANT)
    Q_PROPERTY(bool correct READ correct CONSTANT)
    Q_PROPERTY(QList<int> lettersCorrectness READ lettersCorrectness CONSTANT)

public:
    explicit WordClass(QString str);
    explicit WordClass(QString str, QString correctWord);

    enum Correctness : int{
        LetterNotInWord = 0,
        LetterInAnotherPlace = 1,
        LetterCorrect = 2
    };
    Q_ENUM(Correctness)

public slots:
    QString str() const                     { return _str; }
    bool correct() const                    { return _correct; }
    QList<int> lettersCorrectness() const   { return _lettersCorrectness; }

    bool checkLetters(QString correctWord);
private:
    QString _str;
    bool _correct;
    QList<int> _lettersCorrectness;
};


class WordsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit WordsModel(const QString wordToGuess, QObject* parent = nullptr);

    enum Roles{
        WordRole = Qt::UserRole + 1,
        CorrectRole,
        LettersRole
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void guessWord(QString newWord);

    int numberOfTries() const;
    WordClass* wordAt(int index) const;
    QList<WordClass*> wordTries() const;

signals:
    void wordIsCorrect();
    void wordExistsButNotCorrect();
    void wordDoesNotExist();

    void tooManyTries();

private:

    bool checkIfWordExists(const QString str);
    bool checkLetters(const QString str);

private:
    QString _wordToGuess;
    int _numberOfTries;
    QList<WordClass*> _wordTries;
};

#endif // WORDSMODEL_H
