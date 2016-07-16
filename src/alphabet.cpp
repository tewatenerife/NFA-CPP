#include "alphabet.h"

Alphabet::Alphabet() {}

Alphabet::Alphabet(string input) {
    for (unsigned i = 0; i < input.length(); i++) {
        symbols_.push_back((char) input[i]);
    }
}

Alphabet::~Alphabet() {}

void Alphabet::add_symbol(char symbol) {
    symbols_.push_back(symbol);
}

bool Alphabet::contains_symbol(char symbol) {
    for (unsigned i = 0; i < symbols_.size(); i++) {
        if (symbols_[i] == symbol) {
            return true;
        }
    }

    return false;
}

bool Alphabet::contains_string(string string) {
    for (int i = 0; i < string.length(); i++) {
        if (!contains_symbol(string[i])) {
            return false;
        }
    }

    return true;
}
