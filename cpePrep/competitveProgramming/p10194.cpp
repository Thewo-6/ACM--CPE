#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct Team {
    std::string name;
    int points = 0;
    int games = 0;
    int wins = 0;
    int ties = 0;
    int losses = 0;
    int goalDifference = 0;
    int goalsScored = 0;
    int goalsAgainst = 0;
};

bool compareTeams(const Team &a, const Team &b) {
    if(a.points != b.points) return a.points > b.points;
    if(a.wins != b.wins) return a.wins > b.wins;
    if(a.goalDifference != b.goalDifference) return a.goalDifference > b.goalDifference;
    if(a.goalsScored != b.goalsScored) return a.goalsScored > b.goalsScored;
    if(a.games != b.games) return a.games < b.games;
    return a.name < b.name;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    for(int t = 0; t < N; ++t) {
        std::string tournamentName;
        std::getline(std::cin, tournamentName);

        int T;
        std::cin >> T;
        std::cin.ignore();

        std::map<std::string, Team> teams;
        std::vector<std::string> teamOrder;

        for(int i = 0; i < T; ++i) {
            std::string teamName;
            std::getline(std::cin, teamName);
            Team newTeam;
            newTeam.name = teamName;
            teams[teamName] = newTeam;
            //teams[teamName] = Team{teamName};
            teamOrder.push_back(teamName);
        }

        int G;
        std::cin >> G;
        std::cin.ignore();

        for(int i = 0; i < G; ++i) {
            std::string gameResult;
            std::getline(std::cin, gameResult);


            size_t firstHash = gameResult.find('#');
            size_t atSign = gameResult.find('@');
            size_t secondHash = gameResult.rfind('#');

            std::string team1 = gameResult.substr(0, firstHash);
            int score1 = std::stoi(gameResult.substr(firstHash + 1, atSign - firstHash - 1));
            int score2 = std::stoi(gameResult.substr(atSign + 1, secondHash - atSign - 1));
            std::string team2 = gameResult.substr(secondHash + 1);

            Team &team1Data = teams[team1];
            Team &team2Data = teams[team2];

            team1Data.games++;
            team2Data.games++;
            team1Data.goalsScored += score1;
            team2Data.goalsScored += score2;
            team1Data.goalsAgainst += score2;
            team2Data.goalsAgainst += score1;
            team1Data.goalDifference += (score1 - score2);
            team2Data.goalDifference += (score2 - score1);

            if (score1 > score2) {
                team1Data.points += 3;
                team1Data.wins++;
                team2Data.losses++;
            } else if (score1 < score2) {
                team2Data.points += 3;
                team2Data.wins++;
                team1Data.losses++;
            } else {
                team1Data.points++;
                team2Data.points++;
                team1Data.ties++;
                team2Data.ties++;
            }
        }

        std::vector<Team> sortedTeams;
        for (const auto &teamName : teamOrder) {
            sortedTeams.push_back(teams[teamName]);
        }

        std::sort(sortedTeams.begin(), sortedTeams.end(), compareTeams);

        std::cout << tournamentName << std::endl;
        for(size_t i = 0; i < sortedTeams.size(); ++i) {
            const Team &team = sortedTeams[i];
            std::cout << (i + 1) << ") " << team.name << " " << team.points << "p, "
                      << team.games << "g (" << team.wins << "-" << team.ties << "-"
                      << team.losses << "), " << team.goalDifference << "gd ("
                      << team.goalsScored << "-" << team.goalsAgainst << ")" << std::endl;
        }
        std::cout <<std::endl;

    }
    return 0;
}