#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <string>

using namespace std;

class Input {
private:
    vector<char> input_;
    int head_pos_;

public:
    Input();
    Input(string input);
    ~Input();
    char read_symbol();
    inline char peek_symbol() { return input_[head_pos_]; }
    inline bool is_finished() { return head_pos_ >= input_.size(); }
};

#endif // INPUT_H
