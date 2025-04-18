#include <bits/stdc++.h>
#include "../util/constants.cpp"

using namespace std;

vector<int> get_key_permutation(string key) {
    string sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());
    
    map<char, int> ordered_pos;

    for(int i = 0; i < (int)sorted_key.size(); i++) {
        ordered_pos[sorted_key[i]] = i;
    }

    vector<int> permutation((int)key.size());

    for(int i = 0; i < (int)key.size(); i++) {
        permutation[i] = ordered_pos[key[i]];
    }

    return permutation;
    
}

string apply_permutation(string M, vector<int> p) {
    for(int i = 0; i < (int)M.size(); i += (int)p.size()) {
        string block = M.substr(i, (int)p.size());
        string permutated_block((int)p.size(), ' ');
        for(int j = 0; j < (int)p.size(); j++) {
            permutated_block[j] = block[p[j]];
        }
        M.replace(i, (int)p.size(), permutated_block);
    }
    return M;
}

string transposition_cipher(string M, string keyStr) {
    auto p = get_key_permutation(keyStr);
    while((int)M.size() % (int)keyStr.size() != 0) {
        M += PADDING;
    }
    return apply_permutation(M, p);
}

string readKey() {
    
    auto isValid = [&](string k) -> bool {

        set<char> st(k.begin(), k.end());

        if((int)st.size() != (int)k.size()) {
            cout << "Chave inválida, todos os caracteres devem ser distintos. Tente novamente." << endl;
            return false;
        }

        for(auto &c : st) {
            if(c < 'A' || c > 'Z') {
                cout << "Chave inválida, todos os caracteres devem ser letras maiusculas. Tente novamente." << endl;
                return false;
            }
        }

        if((int)k.size() < 2 || (int)k.size() > 10) {
            cout << "Chave inválida, deve ter entre 2 e 10 caracteres. Tente novamente." << endl;
            return false;
        }

        return true;

    };

    string key;
    cout << "Digite a chave: ";
    while(true) {
        cin >> key;
        if(isValid(key)) {
            break;
        }
    }

    return key;
}

int main() {

    string key = readKey();

    string M;
    cout << "Digite a mensagem: "; cin.ignore();
    getline(cin, M);

    cout << transposition_cipher(M, key) << endl;

}