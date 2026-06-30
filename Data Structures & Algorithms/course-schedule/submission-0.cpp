#include <bits/stdc++.h>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> degree(numCourses, 0);
        vector<int> g[numCourses];
        for(auto v : prerequisites){
            g[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        queue <int> q;
        for(int i = 0; i < numCourses; i++) if(degree[i] == 0) q.push(i);
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            cnt++;
            q.pop();
            for(auto v : g[u]){
                degree[v]--;
                if(degree[v] == 0) q.push(v);
            }
        }
        return cnt == numCourses;
    }
};
