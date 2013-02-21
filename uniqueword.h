#ifndef UNIQUEWORD_H
#define UNIQUEWORD_H

#include <QString>
#include <QList>
#include <QString>

class WordOccurrence {
public:
    uint where;
    bool isCapitalized;

    // factory
    static WordOccurrence createOccurrence(uint pos, bool isCap) {
        return WordOccurrence(pos, isCap);
    }

    // move constructor
    WordOccurrence(const WordOccurrence &&other) {
        where = other.where;
        isCapitalized = other.isCapitalized;
    }

private:
    WordOccurrence(uint pos, bool isCap) : where(pos), isCapitalized(isCap) {}
};

class UniqueWord
{
public:
    // move
    UniqueWord(const UniqueWord &&other) {
        word = other.getWord();
        occurrences = other.getOccurrences();
    }

    inline const QList<WordOccurrence> & getOccurrences() const {
        return occurrences;
    }

    inline const QString & getWord() const {
        return word;
    }

    inline const uint length() const {
        return word.length();
    }

    inline uint getOccurrenceCount() const {
        return occurrences.length();
    }

    inline void addOccurrence(uint where, bool isCap) const {
        occurrences.append(WordOccurrence::createOccurrence(where, isCap));
    }

    // QHash/QSet required interface
    bool operator==(const UniqueWord &other) const {
        return word == other.getWord();
    }
    // no need to make qHash friend instead use accessor

    static UniqueWord createUniqueWord(const QString &source) {
        return UniqueWord(source);
    }

    inline void setSyllables(uint c) {
        syllables = c;
    }

private:
    QString word;
    uchar syllables; // TODO : count syllables only when adding a word initially
    mutable QList<WordOccurrence> occurrences;

    // private constructor - words are only created by a static function with move semantics
    UniqueWord() {}
    UniqueWord(const QString &wordSource) : word(wordSource) {}
};

#endif // UNIQUEWORD_H
