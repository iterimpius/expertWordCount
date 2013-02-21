#ifndef JOBSETTINGS_H
#define JOBSETTINGS_H

#include <QString>
#include <QList>
#include <QSet>
#include <QObject>
#include <QLinkedList>

// cathegories
class WordCathegory {
public:
    WordCathegory(const QString &n) : name(n) {}

    inline QString getName() const {
        return name;
    }
    inline void setName(const QString &n) {
        name = n;
    }

    inline bool operator==(const WordCathegory &other) const {
        return name == other.getName();
    }

    inline void addWord(const QString &word) {
        content.insert(word);
    }

    inline void removeWord(const QString &word) {
        content.remove(word);
    }

private:
    QString name;
    QSet<QString> content;
};


class JobSettings : public QObject
{
    Q_OBJECT
public:
    JobSettings(const QString &v,
                const QString &c,
                const QString &p,
                const qreal cost = 0.0f,
                const qreal reduct = 1.0f,
                const qreal promo = 1.0f,
                const uint wordLength = 5,
                const bool calcCost = 0,
                const bool calcShorter = 0,
                const bool calcLonger = 0
                ) :
        vowels(v),
        consonants(c),
        punctuators(p),
        wordCost(cost),
        reductionFactor(reduct),
        promotonFactor(promo),
        wordLengthBaseline(wordLength),
        calculateTextCost(calcCost),
        calculateShorter(calcShorter),
        calculateLonger(calcLonger),
        name("New setting")
    {}

    inline QString getVowels() {
        return vowels;
    }

    inline QString getConsonants() {
        return consonants;
    }

    inline QString getPunctuators() {
        return punctuators;
    }

    inline qreal getWordCost() {
        return wordCost;
    }

    inline qreal getPromotonFactor() {
        return promotonFactor;
    }

    inline qreal getReductionFactor() {
        return reductionFactor;
    }

    inline uint getWordLengthBaseline() {
        return wordLengthBaseline;
    }

    inline bool getCalculateShorter() {
        return calculateShorter;
    }

    inline bool getCalculateLonger() {
        return calculateLonger;
    }

    inline bool getCalculateTextCost() {
        return calculateTextCost;
    }

    inline QLinkedList<WordCathegory> getCathegories() {
        return cathegories;
    }

public slots:

    inline void setVowels(const QString &v) {
        vowels = v;
    }

    inline void setConsonants(const QString &c) {
        consonants = c;
    }

    inline void setPunctuators(const QString &p) {
        punctuators = p;
    }

    inline void setWordCost(qreal cost) {
        wordCost = cost;
    }

    inline void setPromotonFactor(qreal pF) {
        promotonFactor = pF;
    }

    inline void setReductionFactor(qreal rF) {
        reductionFactor = rF;
    }

    inline void setWordLengthBaseline(uint wL) {
        wordLengthBaseline = wL;
    }

    inline void setCalculateShorter(bool v) {
        calculateShorter = v;
    }

    inline void setCalculateLonger(bool v) {
        calculateLonger = v;
    }

    inline void setCalculateTextCost(bool v) {
        calculateTextCost = v;
    }

    inline void createCathegory(const QString &n) {
        WordCathegory c(n);
        if (!cathegories.contains(c)) {
            cathegories.append(c);
        }
    }

    inline void deleteCathegory(const QString &n) {
        WordCathegory c(n);
        if (cathegories.contains(c)) {
            cathegories.removeAll(c);
        }
    }

    inline void setName(const QString &n) {
        name = n;
    }

    inline const QString & getName() {
        return name;
    }

    // TODO saveSetting
    inline void saveSettings() {

    }

    // TODO loadSetting
    inline void loadSettings() {

    }


private:
    QString vowels, consonants, punctuators, name;
    QLinkedList<WordCathegory> cathegories;

    // text cost related
    qreal wordCost, reductionFactor, promotonFactor;
    uint wordLengthBaseline;
    bool calculateShorter, calculateLonger, calculateTextCost, isDirty; // TODO write dirty settings to disk


};

#endif // JOBSETTINGS_H
