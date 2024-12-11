#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

struct Contestant {
    int id;
    int problemsSolved;
    int penaltyTime;
    int problemsAttempted[10];

    // Default constructor
    Contestant() : id(0), problemsSolved(0), penaltyTime(0) {
        fill(problemsAttempted, problemsAttempted + 10, 0);
    }

    Contestant(int Id) : id(Id), problemsSolved(0), penaltyTime(0) {
        fill(problemsAttempted, problemsAttempted + 10, 0);
    }

    void addSubmission(int problem, int time, char result) {
        if (result == 'C') {
            if (problemsAttempted[problem] != -1) {
                problemsSolved++;
                penaltyTime += time + (problemsAttempted[problem] * 20);
                problemsAttempted[problem] = -1;
            }
        } else if (result == 'I') {
            if (problemsAttempted[problem] != -1) {
                problemsAttempted[problem]++;
            }
        }
    }
};

bool compare(const Contestant &a, const Contestant &b) {
    if(a.problemsSolved != b.problemsSolved)
        return a.problemsSolved > b.problemsSolved;
    if(a.penaltyTime != b.penaltyTime)
        return a.penaltyTime < b.penaltyTime;
    return a.id < b.id;
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();

    string line;
    getline(cin, line); // Read the blank line after the number of test cases

    while(testCases--) {
        map<int, Contestant> scoreboard;

        while(getline(cin, line) && !line.empty()) {
            int contestant, problem, time;
            char result;
            istringstream ss(line);
            ss >> contestant >> problem >> time >> result;

            if(scoreboard.find(contestant) == scoreboard.end()) {
                //scoreboard.emplace(contestant, contestant);
                scoreboard[contestant] = Contestant(contestant);
            }

            scoreboard[contestant].addSubmission(problem, time, result);
        }

        vector<Contestant> results;
        for(auto &entry : scoreboard) {
            results.push_back(entry.second);
        }

        sort(results.begin(), results.end(), compare);

        for(const auto &contestant : results) {
            cout << contestant.id << " " << contestant.problemsSolved << " " << contestant.penaltyTime << endl;

        }

        if(testCases) cout << endl; // Separate test cases by a blank line
    }

    return 0;
}