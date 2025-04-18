#include <bits/stdc++.h>
using namespace std;

string shift_cypher(string M, int shift) {

    int alphabetSize = 26;
    shift = (shift + alphabetSize) % alphabetSize; // garante que o deslocamento seja positivo
    shift %= alphabetSize; // nao faz sentido shiftar mais que isso

    string result = M;

    for(auto &c : result) {
        // shifta apenas letras
        if(c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
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