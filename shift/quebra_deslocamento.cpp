#include <bits/stdc++.h>
#include "../util.cpp"
#include "../decypher_analysis_util.cpp"

using namespace std;

int getShiftScore(string& s, set<string>& words) {
    vector<int> dp((int)s.size(), -1);
    return score(0, s, dp, words);;
}

string decypher_brute(string s) {
    int alphabetSize = 26;
    
    int bestScore = 0;
    int bestScoreAt = 0;

    auto words = parse_raw_words(read_words());

    for(int shift = 0; shift < alphabetSize; shift++) {
        auto r = getShiftScore(s, words);
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
    int alphabetSize = 26;
    auto freq = getFrequencyData();

    int bestScore = 0;
    int bestScoreAt = 0;

    for(int shift = 0; shift < alphabetSize; shift++) {
        auto r = getStringFreq(s);
        int score = getFreqScore(r, freq);

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