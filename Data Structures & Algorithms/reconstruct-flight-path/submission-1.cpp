#include <bits/stdc++.h>

class Solution {
public:
    unordered_map <string, priority_queue<string, vector<string>, greater<string>>> g;
    vector <string> path;
    void dfs(string u){
        while(!g[u].empty()){
            string v = g[u].top();
            g[u].pop();
            dfs(v);
        }
        path.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it : tickets){
            g[it[0]].push(it[1]);
        }
        dfs("JFK");
        reverse(path.begin(), path.end());

        return path;
    }
};
