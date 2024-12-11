/* #include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start, vector< vector<int> >& graph, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;

        vector< vector<int> > graph(n + 1);
        vector<bool> visited(n + 1, false);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        for (int i = 0; i < l; i++) {
            int z;
            cin >> z;
            if (!visited[z]) {
                visited[z] = true;
                dfs(z, graph, visited);
            }
        }

        int fallen_count = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                fallen_count++;
            }
        }

        cout << fallen_count << endl;
    }

    return 0;
}
 */

//uva11518
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int knockDown(int from, int down[], vector<vector<int> > &road){

    int count = 0;
    queue<int> q;
    
    // start bfs
    q.push(from);
    while (!q.empty()){
        int len = q.size();
        for (int i = 1; i <= len; i++){
            int domino = q.front();
            if (!down[domino]){
                for (int j = 0; j < road[domino].size(); j++)
                    q.push(road[domino][j]);
                down[domino] = 1;
                count++;
            }
            q.pop();
        }
    }
    return count;
}


int main() {
    int t, n, m, l;
    cin >> t;

    while(t--){
        int from, to;
        vector<vector<int> > road(10001);
       
        cin >> n >> m >> l;
        for (int i = 1; i <= m; i++){
            cin >> from >> to;
            road[from].push_back(to);
        }

        int down[10001] = {0}, total = 0;
        for (int i = 1; i <= l; i++){
            cin >> from;
            //cout << knockDown(from, down, road) << "\n";
            total += knockDown(from, down, road);
        }
        cout << total << "\n";
    }
}