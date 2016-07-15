#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
#include <iostream>

using namespace std;

class Transition {
private:
    string current_state_;
    char read_symbol_;
    string next_state_;

public:
    Transition();
    Transition(string currentStateId, char symbolToRead, string nextStateId);
    ~Transition();
    string get_current_state() { return current_state_; }
    void set_current_state(string stateId);
    inline char get_read_symbol() { return read_symbol_; }
    void set_read_symbol(char symbol);
    string get_next_state() { return next_state_; }
    void set_next_state(string stateId);
    friend ostream& operator<<(ostream& os, const Transition& trans);
};

#endif // TRANSITION_H
