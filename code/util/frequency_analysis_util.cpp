#include <bits/stdc++.h>
using namespace std;

string frequency_data_file_path = "../../data/frequency.txt";

vector<char> get_frequency_data() {
    ifstream file(frequency_data_file_path);
    string line;
    map<char, double> freq_map;
    vector<char> freq_vector;
    while (getline(file, line)) {
        char c = line[0];
        double freq = stod(line.substr(2));
        freq_map[c] = freq;
        freq_vector.push_back(c);
    }

    sort(freq_vector.begin(), freq_vector.end(), [&](char a, char b) {
        return freq_map[a] > freq_map[b];
    });

    return freq_vector;
}

vector<char> get_string_freq(string s) {
    map<char, int> freq_map;
    vector<char> freq_vector;

    for(auto &c : s) {
        if(c >= 'a' && c <= 'z') {
            freq_map[c]++;
        }
    }

    for(auto &p : freq_map) {
        freq_vector.push_back(p.first);
    }

    sort(freq_vector.begin(), freq_vector.end(), [&](char a, char b) {
        return freq_map[a] > freq_map[b];
    });

    return freq_vector;
}

int get_freq_score(vector<char>& r, vector<char>& freq) {
    int score = 0;
    for(int i = 0; i < (int)r.size(); i++) {
        score += (r[i] == freq[i]);
    }
    return score;
}