#ifndef NFA_H
#define NFA_H

#include "state.h"
#include "transition.h"
#include "alphabet.h"
#include "input.h"

#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;

class NFA {
private:
    vector<State> states_;
    Alphabet input_alphabet_;
    Input input_;
    vector<Transition> transitions_;

public:
    NFA();
    NFA(string file_name);
    NFA(const NFA& nfa);
    ~NFA();
    void simulate(string input);
    void simulate_r(Input input, string current_state, vector<Transition> transitions);
    State* get_state(const string id);
    vector<Transition> get_transitions(string state_id, char read_symbol);
    vector<Transition> get_transitions(string state_id);
    string get_initial_state();
    vector<string> get_death_states();
    void show_death_states();
    friend ostream& operator<<(ostream& os, const NFA& nfa);

    static const char EPSILON = '$';

private:
    void read_from_file(string filename);
};

#endif // NFA_H
