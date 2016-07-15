#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>
#include <string>

using namespace std;

class Alphabet {
private:
    vector<char> symbols_;

public:
    Alphabet();
    Alphabet(string input);
    Alphabet(const Alphabet& alph);
    ~Alphabet();
    inline vector<char> get_symbols() { return symbols_; }
    inline void set_symbols(vector<char> symbols) { symbols_ = symbols; }
    void add_symbol(char symbol);
    bool contains_symbol(char symbol);
    inline int size() { return symbols_.size(); }
};

#endif // ALPHABET_H
