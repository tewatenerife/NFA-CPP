#include "input.h"

Input::Input() {}

Input::Input(string input): head_pos_(0) {
    for (unsigned i = 0; i < input.length(); i++) {
        input_.push_back((char) input[i]);
    }
}

Input::~Input() {}

char Input::read_symbol() {
    if (!is_finished()) {
        char symbol = input_[head_pos_];
        head_pos_++;
        return symbol;
    } else {
        return NULL;
    }
}
