#ifndef STATE_H
#define STATE_H

#include <string>
#include <iostream>

using namespace std;

class State {
private:
    string id_;
    bool initial_;
    bool final_;

public:
    State();
    State(string id);
    ~State();
    inline string get_id() { return id_; }
    inline void set_id(string id) { id_ = id; }
    inline bool is_initial() {return initial_; }
    inline void set_initial(bool initial) { initial_ = initial; }
    inline bool is_final() { return final_; }
    inline void set_final(bool final) { final_ = final; }
    friend ostream& operator<<(ostream& os, const State& state);
};

#endif // STATE_H
