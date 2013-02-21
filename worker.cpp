#include "worker.h"





void Worker::indexCharacters()
{
    for (int i = 0; i < lookup.length(); ++i) {
        lookup[i] = CHAR_IGNORE;
    }
    QString v = setting->getVowels();
    QString c = setting->getConsonants();
    QString p = setting->getPunctuators();

    for (int i =0; i < v.length(); ++i) {
        lookup[v.at(i).unicode()] = CHAR_VOWEL;
    }

    for (int i =0; i < c.length(); ++i) {
        lookup[c.at(i).unicode()] = CHAR_CONSONANT;
    }

    for (int i =0; i < p.length(); ++i) {
        lookup[p.at(i).unicode()] = CHAR_PUNCTUATOR;
    }
}





// for qHash
uint qHash(const UniqueWord &key)
{
    return qHash(key.getWord());
}

