#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct atom
{
    string name;
    int charge;
    int mass;
};

struct reaction
{
    string name;
    string reac;
};

void ch_reaction(reaction react, int N, atom array[]) {
    atom Atom;
    for (int k = 0; k < N; k++) {
        if (array[k].name == react.name) {
            Atom = array[k];
            break;
        }
    }

    if (react.reac == "alpha") {
        Atom.charge -= 2;
        Atom.mass -= 4;
    } else if (react.reac == "beta+") {
        Atom.charge--;
    } else {
        Atom.charge++;
    }

    for (int k = 0; k < N; k++) {
        if (array[k].charge == Atom.charge and Atom.mass == array[k].mass) {
            cout << array[k].name << ' ';
            return;
        }
    }
    cout << "NO DATA ";
    return;
}

int main() {
    int N, M, index;
    cin >> N;
    atom data_atoms[N];
    for (int i = 0; i < N; i++) {
        cin >> data_atoms[i].name >> data_atoms[i].mass >> data_atoms[i].charge;
    }

    cin >> M;
    reaction data_reactions[M];
    for (int i = 0; i < M; i++) {
        cin >> data_reactions[i].name >> data_reactions[i].reac;
        ch_reaction(data_reactions[i], N, data_atoms);
    }

    return 0;
}
// 6 U 238 92 Cd 112 48 Cr 52 24 Ag 108 47 Th 234 90 In 112 49 7 U alpha Cd beta+ Cd beta- In beta+ Cd beta+ Th alpha U
// beta-