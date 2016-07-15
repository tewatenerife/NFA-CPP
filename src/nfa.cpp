#include "nfa.h"

NFA::NFA() {}

NFA::NFA(string file_name):
    states_(),
    input_alphabet_(),
    input_()
{
    read_from_file(file_name);
}

NFA::~NFA() {}

void NFA::read_from_file(string filename) {
    ifstream file(filename.c_str());
    string id;

    if (file.is_open()) {
        // Estados
        int nstates;
        file >> nstates;
        for (int i = 0; i < nstates; i++) {
            file >> id;
            State new_state(id);
            states_.push_back(new_state);
        }

        // Alfabeto de entrada
        int nsymbols;
        file >> nsymbols;
        for (int i = 0; i < nsymbols; i++) {
            file >> id;
            input_alphabet_.add_symbol(id[0]);
        }

        // Estado inicial
        string initial_q;
        file >> initial_q;
        get_state(initial_q)->set_initial(true);

        // Estados finales
        int nfinals;
        file >> nfinals;
        for (int i = 0; i < nfinals; i++) {
            file >> id;
            get_state(id)->set_final(true);
        }

        // Transiciones
        int ntransitions;
        file >> ntransitions;
        string current_state;
        char read_symbol;
        string next_state;
        for (int i = 0; i < ntransitions; i++) {
            file >> current_state >> read_symbol >> next_state;
            Transition new_transition(current_state, read_symbol, next_state);
            transitions_.push_back(new_transition);
        }

        file.close();
    }
}

void NFA::simulate(string input_string) {
    Input input(input_string);
    vector<Transition> transitions;
    simulate_r(input, get_initial_state(), transitions);
}

void NFA::simulate_r(Input input, string current_state, vector<Transition> transitions) {
    vector<Transition> possible_transitions(get_transitions(current_state, input.peek_symbol()));

    if (possible_transitions.size() == 0 || input.is_finished()) {
        // Visualizar camino
        for (int i = 0; i < transitions.size(); i++) {
            cout << transitions[i] << endl;
        }

        if (get_state(current_state)->is_final() && input.is_finished()) {
            cout << "Cadena de entrada ACEPTADA" << endl;
        } else {
            cout << "Cadena de entrada NO ACEPTADA" << endl;
        }

    } else {
        for (int i = 0; i < possible_transitions.size(); i++) {
            Input new_input(input);
            vector<Transition> new_transitions(transitions);
            if (possible_transitions[i].get_read_symbol() == new_input.peek_symbol()) {
                new_input.read_symbol();
                new_transitions.push_back(possible_transitions[i]);
                simulate_r(new_input, possible_transitions[i].get_next_state(), new_transitions);

            } else if (possible_transitions[i].get_read_symbol() == NFA::EPSILON) {
                new_transitions.push_back(possible_transitions[i]);
                simulate_r(new_input, possible_transitions[i].get_next_state(), new_transitions);
            }
        }
    }
}

void NFA::show_death_states() {
    vector<string> states = get_death_states();

    if (states.size() > 0) {
        cout << "Estados de muerte: ";
        for (int i = 0; i < states.size(); i++) {
            cout << states[i];
            if (i != states.size() - 1) {
                cout << ", ";
            }
        }
    } else {
        cout << "No hay estados de muerte" << endl;
    }
}

string NFA::get_initial_state() {
    for (unsigned i = 0; i < states_.size(); i++) {
        if (states_[i].is_initial()) {
            return states_[i].get_id();
        }
    }

    return "";
}

State* NFA::get_state(const string id) {
    for (unsigned i = 0; i < states_.size(); i++) {
        if (states_[i].get_id() == id) {
            return &states_[i];
        }
    }

    return NULL;
}

vector<Transition> NFA::get_transitions(string state_id, char read_symbol) {
    vector<Transition> transitions;
    for (unsigned i = 0; i < transitions_.size(); i++) {
        if (transitions_[i].get_current_state() == state_id && transitions_[i].get_read_symbol() == read_symbol) {
            transitions.push_back(transitions_[i]);

        } else if (transitions_[i].get_current_state() == state_id && transitions_[i].get_read_symbol() == NFA::EPSILON) {
            transitions.push_back(transitions_[i]);
        }
    }
    return transitions;
}

vector<Transition> NFA::get_transitions(string state_id) {
    vector<Transition> transitions;
    for (unsigned i = 0; i < transitions_.size(); i++) {
        if (transitions_[i].get_current_state() == state_id) {
            transitions.push_back(transitions_[i]);
        }
    }

    return transitions;
}

vector<string> NFA::get_death_states() {
    vector<string> not_death_states;
    vector<string> death_states;

    for (unsigned i = 0; i < states_.size(); i++) {
        vector<Transition> state_trans = get_transitions(states_[i].get_id());
        for (unsigned i = 0; i < state_trans.size(); i++) {
            if (state_trans[i].get_current_state() != state_trans[i].get_next_state()) {
                not_death_states.push_back(state_trans[i].get_current_state());
            }
        }
    }

    for (unsigned i = 0; i < states_.size(); i++) {
        if (find(not_death_states.begin(), not_death_states.end(), states_[i].get_id()) == not_death_states.end()) {
            death_states.push_back(states_[i].get_id());
        }
    }

    return death_states;
}

ostream& operator<<(ostream& os, const NFA& nfa) {
    os << "not implemented yet" << endl;
}
