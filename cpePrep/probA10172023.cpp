#include <iostream>
#include <string>
using namespace std;
int main() {
    int n,k,w; cin>>n;
    while(cin>>k>>w) {string ans;cin>>ans;w--;
        while(w--) {string s; cin>>s;
            for(int h=s.size(); h>=0;h--) {
                if(s.substr(0,h)==ans.substr(ans.size()-h)) {
                    ans+=s.substr(h);break;
                }
            }
        }
        cout<<ans.size()<<endl;
    }
    return 0;
}