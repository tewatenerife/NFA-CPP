#include "transition.h"

Transition::Transition() {}

Transition::Transition(string currentStateId, char symbolToRead, string nextStateId):
    current_state_(currentStateId),
    read_symbol_(symbolToRead),
    next_state_(nextStateId)
{}

Transition::~Transition() {
    current_state_ = -1;
    next_state_ = -1;
}

ostream& operator<<(ostream& os, const Transition& trans) {
    os << trans.current_state_ << "                     ";
    os << trans.read_symbol_ << "                  ";
    os << trans.next_state_;
    return os;
}
