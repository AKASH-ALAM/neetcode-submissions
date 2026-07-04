class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <pair<int, int>> g[n+1];
        for(auto have : times){
            int u = have[0];
            int v = have[1];
            int w = have[2];
            g[u].push_back({v, w});
        }

        vector <int> dis(n+1, 1e8);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dis[k] = 0;

        while(!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            if(dis[u] < w) continue;
            for(auto [v, time] : g[u]){
                if(w + time < dis[v]){
                    dis[v] = w + time;
                    pq.push({dis[v], v});
                }
            }
        }
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            mx = max(mx, dis[i]);
        }
        return mx == 1e8 ? -1 : mx;
    }
};
