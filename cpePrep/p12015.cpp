#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct webpage {
    string URL;
    int relevance;
};

int main() {
    int cases; cin >> cases;
    for(int i = 1; i <= cases; ++i)
    {
        vector <webpage> pages(10);
        int max = 0;
        for(int j = 0; j < 10; ++j)
        {
            cin >> pages[j].URL >> pages[j].relevance;
            if(pages[j].relevance > max)
                max = pages[j].relevance;
        }
        
        cout << "Case #" << i << " :" << endl;
        for(const auto& Webpage : pages)
        {
            if(Webpage.relevance == max)
            {
                cout << Webpage.URL << endl;
            }
        }
    }

    return 0;
}