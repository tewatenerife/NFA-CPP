#include "nfa.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string filename;
    char option;
    NFA *nfa = NULL;

    cout << "Simulador de NFAs" << endl;

    do {
        cout << "\n(l)eer DFA" << endl;
        cout << "(m)ostrar NFA" << endl;
        cout << "(i)dentificar estados de muerte" << endl;
        cout << "(a)nalizar cadena" << endl;
        cout << "(s)alir" << endl;

        cout << "\nIntroduzca una opción: ";
        cin >> option;
        option = tolower(option);

        switch (option) {
            case 'l':
                cout << "Fichero de especificación de NFA: ";
                cin >> filename;
                nfa = new NFA(filename);
                break;

            case 'm':
                if (nfa != NULL) {
                    cout << *nfa << endl;
                } else {
                    cout << "NFA no especificado todavía" << endl;
                }
                break;

            case 'i':
                if (nfa != NULL) {
                    nfa->show_death_states();
                    cout << endl;
                } else {
                    cout << "NFA no especificado todavía" << endl;
                }
                break;

            case 'a':
                if (nfa != NULL) {
                    string input_string;
                    cout << "Cadena de entrada: ";
                    cin >> input_string;
                    nfa->simulate(input_string);
                } else {
                    cout << "NFA no especificado todavía" << endl;
                }
                break;

            default: cout << "Opción no reconocida" << endl;
        }
    } while (option != 's');
}
