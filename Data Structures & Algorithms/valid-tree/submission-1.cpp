#include <bits/stdc++.h>

class Solution {
public:
    bool dfs(int u, int p, vector <bool> &vis, vector <int> *g){
        vis[u] = 1;
        for(auto v : g[u]){
            if(!vis[v]) {
                if(!dfs(v, u, vis, g)) return false;
            }
            else if(v != p) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector <int> g[n];
        for(auto it : edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector <bool> vis(n, 0);
        bool have = dfs(0, -1, vis, g);
        for(int i = 0; i < n; i++) if(!vis[i]){
            have = false;
            break;
        }
        return have;
    }
};
