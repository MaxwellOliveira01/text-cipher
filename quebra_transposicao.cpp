#include <bits/stdc++.h>
#include "util.cpp"
#include "constants.cpp"

using namespace std;

string decipher_brute(string M, set<string>& words) {
    auto divs = get_divisors((int)M.size());

    string best = M;
    int best_score = get_score(M, words);

    for(auto &d : divs) if(d < MAX_DIVISOR_TO_TEST) {
        // pra esse divisor fixo, ainda preciso testar todas as chaves

        vector<int> p(d);
        iota(p.begin(), p.end(), 0);

        do {
            // suponha que P seja a chave
            // nesse caso, eu precisaria calcular a permutação inversa
            // pra desfazer a transposição, mas....
            // cada permutação P tem uma unica permutação inversa P'
            // entao posso supor que meu P atual não é a chave, mas
            // a permutação inversa P' da chave
            // e simplesmente aplicar a permutação e calcular a score

            string msg = apply_permutation(M, p);
            int score = get_score(msg, words);

            if(score > best_score) {
                best = msg;
                best_score = score;
                // poderia salvar o inverso da chave aqui
            }

        } while(next_permutation(p.begin(), p.end()));

    }

    return best;

}

int main() {

    string message;
    cout << "Digite a mensagem:\n";
    getline(cin, message);

    set<string> words = parse_raw_words(read_words());

    cout << decipher_brute(message, words) << endl;

}