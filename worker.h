#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QObject>

#include "jobsettings.h"
#include "uniqueword.h"

enum CharacterType {
    CHAR_IGNORE,
    CHAR_PUNCTUATOR,
    CHAR_VOWEL,
    CHAR_CONSONANT
};

enum JobType {
    JOB_READ_LOCAL,
    JOB_READ_TXT,
    JOB_READ_HTML,
    JOB_READ_URL,
    JOB_READ_URLLIST_FROM_TEXT,
    JOB_READ_URLLIST_FROM_FILE,
    JOB_READ_DOCX,
    JOB_READ_OPENOFFICE,
    JOB_READ_EPUB,
    JOB_READ_PDF
};

class Worker : public QThread
{
public:
    Worker(JobType t, QObject *parent = 0);

    void run(); // TODO work method

signals:
    void error(const QString &err);

public slots:

private:
    void readURL(const QString &url); // TODO
    void readURLList(const QString &path); // TODO read by line into a string list
    void readDOCX(const QString &path); // TODO read zips
    void readOpenOffice(const QString &path);
    void readEpub(const QString &path);
    void readPDF(const QString &path);

    void fileToString(const QString &path, QString &target);
    void removeTags(const QString &from, QString &to); // TODO trim

    JobType type;
    QString text, source;
    QSet<UniqueWord> words;

    // stats
    uint totalWords, uniqueWords, totalCharacters, textCharacters, otherCharacters;

    QByteArray lookup;
    void indexCharacters();

    // the setting
    JobSettings *setting;

};

#endif // WORKER_H
