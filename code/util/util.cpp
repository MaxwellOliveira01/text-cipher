#include <bits/stdc++.h>
using namespace std;

vector<string> wordsPath = {
    "../../data/nomes.txt",
    "../../data/first-name-pt-br.txt",
    "../../data/brazilian-soccer-teams.txt",
    "../../data/br-utf8.txt",
    "../../data/br-sem-acentos.txt",
    // "data/biblic-words-pt-br.txt", --> acsa
};

vector<string> read_words() {
    vector<string> words;
    for (const auto& path : wordsPath) {
        ifstream file(path);
        string word;
        while (file >> word) {
            words.push_back(word);
        }
    }
    return words;
}

set<string> parse_raw_words(vector<string> rawWords) {
    set<string> words;
    for(auto &w : rawWords) if((int)w.size() > 2) {
        transform(w.begin(), w.end(), w.begin(), ::toupper);
        words.insert(w);
        transform(w.begin(), w.end(), w.begin(), ::tolower);
        words.insert(w);
    }
    return words;
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

const int INF = 1000000;

int score(int i, string& s, vector<int>& dp, set<string>& words) {
    if(i >= (int)s.size()) {
        return (i == (int)s.size() ? 0 : -INF);
    }

    auto &ans = dp[i];

    if(ans != -1) {
        return ans;
    }

    ans = -INF;

    // ans = score(i + 1, s, dp, words);

    string current_substring = "";

    for(int j = i; j < (int)s.size(); j++) {
        current_substring += s[j];
        if(words.count(current_substring)) {
            ans = max(ans, 1 + score(j + 1, s, dp, words));
        }
        // ans = max(ans, score(j + 1, s, dp, words));
    }

    return ans;

}

int get_score(string& s, set<string>& words) {
    vector<int> dp((int)s.size(), -1);
    return score(0, s, dp, words);
}

vector<int> get_divisors(int N) {
    vector<int> divs;

    for(int i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            divs.push_back(i);
            if(i != N / i) {
                divs.push_back(N / i);
            }
        }
    }

    return divs;
}

void shift_string(string &s, int shift = 1) {
    int alphabetSize = 26;
    shift = (shift + alphabetSize) % alphabetSize;
    for(auto &c : s) {
        if(c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % alphabetSize + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % alphabetSize + 'A';
        }
    }
}

string to_lower(string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return s;
}