#include <bits/stdc++.h>

class Solution {
public:
    void dfs(int u, vector <bool> &vis, vector <int> *g){
        vis[u] = 1;
        for(auto v : g[u]){
            if(!vis[v]) dfs(v, vis, g);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector <int> g[n];
        for(auto it : edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector <bool> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]) {
                cnt++;
                dfs(i, vis, g);
            }
        }
        return cnt;
    }
};