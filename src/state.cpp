#include "state.h"

State::State() {}

State::State(string id): id_(id), initial_(false), final_(false)
{}

State::~State() {
    id_ = -1;
    initial_ = false;
    final_ = false;
}

ostream& operator<<(ostream& os, const State& state) {
    os << state.id_;
    if (state.final_ == true) {
        os << "*";
    }
    return os;
}
