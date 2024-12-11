#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countInversions(const string& s) {
    int inversions = 0;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if(a.second == b.second)
        return false; // Maintain original order if inversion count is the same
    return a.second < b.second;
}

int main() {
    int M;
    cin >> M;
    cin.ignore();

    while (M--) {
        int n, m;
        cin >> n >> m;
        cin.ignore();

        vector< pair<string, int> > sequences;

        for(int i = 0; i < m; i++) {
            string s;
            getline(cin, s);
            int inversions = countInversions(s);
            sequences.push_back(make_pair(s, inversions));
        }

        stable_sort(sequences.begin(), sequences.end(), compare);

        for(auto& seq : sequences) {
            cout << seq.first << endl;
        }

        if(M > 0) {
            cout << endl;
        }
    }

    return 0;
}