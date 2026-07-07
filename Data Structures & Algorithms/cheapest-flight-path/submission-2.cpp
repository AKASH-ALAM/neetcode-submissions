#include <bits/stdc++.h>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <pair<int, int>> g[105];
        for(auto it : flights){
            g[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<pair<int, int>, int>, vector <pair<pair<int, int>, int>>, greater <>> pq;
        vector <int> dis(n+1, 1e8);
        pq.push({{0, 0}, src});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int u = it.second;
            int cnt = it.first.first;
            int w = it.first.second;

            // if(cnt <= k + 1 and u == dst) return w;

            for(auto [v, cost] : g[u]){
                if(cnt <= k and w + cost < dis[v]){
                    dis[v] = w + cost;
                    pq.push({{cnt + 1, w + cost}, v});
                }
            }
        }
        if(dis[dst] != 1e8) return dis[dst];
        return -1;
    }
};
