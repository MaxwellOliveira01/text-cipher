#include <bits/stdc++.h>
using namespace std;

vector<int> getKeyPermutation(string key) {
    string t = key;
    sort(t.begin(), t.end());
    
    map<char, int> tpos; // posicao da letra na chave ordenada

    for(int i = 0; i < (int)t.size(); i++) {
        tpos[t[i]] = i;
    }

    vector<int> perm((int)key.size());

    for(int i = 0; i < (int)key.size(); i++) {
        perm[i] = tpos[key[i]];
    }

    return perm;
    
}

string apply_permutation(string M, vector<int> p) {
    for(int i = 0; i < (int)M.size(); i += (int)p.size()) {
        string t = M.substr(i, (int)p.size());
        string t2((int)p.size(), ' ');

        for(int j = 0; j < (int)p.size(); j++) {
            t2[j] = t[p[j]];
        }

        M.replace(i, (int)p.size(), t2);
    }

    return M;
}

string transposition_cipher(string M, string keyStr) {

    auto p = getKeyPermutation(keyStr);

    while((int)M.size() % (int)keyStr.size() != 0) {
        M += '*';
    }

    return apply_permutation(M, p);

    // for(int i = 0; i < (int)M.size(); i += (int)p.size()) {
    //     string t = M.substr(i, (int)p.size());
    //     string t2((int)p.size(), ' ');

    //     for(int j = 0; j < (int)p.size(); j++) {
    //         t2[j] = t[p[j]];
    //     }

    //     M.replace(i, (int)p.size(), t2);
    // }

    return M;

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