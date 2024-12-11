#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// Function to check if two cards match
bool match(const string& card1, const string& card2) {
    return card1[0] == card2[0] || card1[1] == card2[1];
}

// Function to simulate the game
void playAccordion(vector< stack<string> >& piles) {
    for(size_t i = 0; i < piles.size(); ++i) {
        //check if we can move this pile to the left (1 position or 3 positions)
        if(i >= 3 && match(piles[i].top(), piles[i-3].top())) {
            piles[i-3].push(piles[i].top());
            piles[i].pop();
            if(piles[i].empty()) piles.erase(piles.begin() + i);
            i -= 4; // Recheck the previous piles since the current pile is moved
        } else if (i >= 1 && match(piles[i].top(), piles[i-1].top())) {
            piles[i-1].push(piles[i].top());
            piles[i].pop();
            if(piles[i].empty()) piles.erase(piles.begin() + i);
            i -= 2; // Recheck the previous pile since the current pile is moved
        }
    }
}

int main() {
    string card;
    vector< stack<string> > piles;

    while(cin >> card && card != "#") {
        stack<string> newPile;
        newPile.push(card);
        piles.push_back(newPile);

        // If we have read 52 cards, simulate the game
        if(piles.size() == 52) {
            playAccordion(piles);
            // Print the result
            cout << piles.size() << " pile" << (piles.size() > 1 ? "s" : "") << " remaining:";
            for(const auto& pile : piles) {
                cout << " " << pile.size(); // Number of cards in each pile
            }
            cout << endl;
            piles.clear();
        }
    }

    return 0;
}