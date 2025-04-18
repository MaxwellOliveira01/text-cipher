#include <bits/stdc++.h>

#include "../util/util.cpp"
#include "../util/constants.cpp"
#include "../util/decypher_analysis_util.cpp"

using namespace std;

string decypher_brute(string s) {
    int bestScore = 0;
    int bestScoreAt = 0;

    auto words = parse_raw_words(read_words());

    for(int shift = 0; shift < ALPHABET_SIZE; shift++) {
        auto r = get_score(s, words);
        if(r > bestScore) {
            bestScore = r;
            bestScoreAt = shift;
        }
        shift_string(s);
    }

    shift_string(s, bestScoreAt);

    return s;

}

string decypher_analysis(string s) {
    auto freq = get_frequency_data();

    int bestScore = 0;
    int bestScoreAt = 0;

    for(int shift = 0; shift < ALPHABET_SIZE; shift++) {
        auto r = get_string_freq(s);
        int score = get_freq_score(r, freq);

        if(score > bestScore) {
            bestScore = score;
            bestScoreAt = shift;
        }

        shift_string(s);
    }

    shift_string(s, bestScoreAt);
    return s;

}

int main() {
    string S;
    cout << "Digite a string a ser decifrada: ";
    getline(cin, S);

    S = to_lower(S);

    auto result = decypher_brute(S);
    cout << "Resultado com força bruta:\n" << result << "\n";

    cout << "\n";

    auto rfreq = decypher_analysis(S);
    cout << "Resultado com analise de frequencia:\n" << rfreq << "\n";
}