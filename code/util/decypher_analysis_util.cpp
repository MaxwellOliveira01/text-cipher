#include <bits/stdc++.h>
using namespace std;

string frequencyDataFilePath = "data/frequency.txt";

vector<char> get_frequency_data() {
    ifstream file(frequencyDataFilePath);
    string line;
    map<char, double> freqMap;
    vector<char> freqVector;
    while (getline(file, line)) {
        char c = line[0];
        double freq = stod(line.substr(2));
        freqMap[c] = freq;
        freqVector.push_back(c);
    }

    sort(freqVector.begin(), freqVector.end(), [&](char a, char b) {
        return freqMap[a] > freqMap[b];
    });

    return freqVector;
}

vector<char> get_string_freq(string s) {
    map<char, int> freqMap;
    vector<char> freqVector;

    for(auto &c : s) {
        if(c >= 'a' && c <= 'z') {
            freqMap[c]++;
        }
    }

    for(auto &p : freqMap) {
        freqVector.push_back(p.first);
    }

    sort(freqVector.begin(), freqVector.end(), [&](char a, char b) {
        return freqMap[a] > freqMap[b];
    });

    return freqVector;
}

int get_freq_score(vector<char>& r, vector<char>& freq) {
    int score = 0;
    for(int i = 0; i < (int)r.size(); i++) {
        score += (r[i] == freq[i]);
    }
    return score;
}