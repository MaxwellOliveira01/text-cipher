#include <bits/stdc++.h>
#include "../util/constants.cpp"

using namespace std;

string shift_cypher(string M, int shift) {
    string result = M;
    
    shift = (shift + ALPHABET_SIZE) % ALPHABET_SIZE; // ensure shift > 0

    for(auto &c : result) {
        if(c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % ALPHABET_SIZE + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % ALPHABET_SIZE + 'A';
        }
    }

    return result;
}

int main() {
    string S;
    cout << "Digite a string a ser cifrada: ";
    getline(cin, S);

    int deslocamento = 0;
    cout << "Digite o deslocamento: ";
    cin >> deslocamento;

    cout << "String cifrada: " << shift_cypher(S, deslocamento) << endl;
}