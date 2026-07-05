#include <bits/stdc++.h>

class Solution {
public:
    unordered_map <string, vector <string>> g;
    vector <string> path;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it : tickets){
            g[it[0]].push_back(it[1]);
        }
        for(auto &[tmp, it] : g) sort(it.rbegin(), it.rend());
        stack <string> st;
        st.push("JFK");

        while(!st.empty()){
            string u = st.top();
            if(!g[u].empty()){
                int len = g[u].size();
                string v = g[u][len-1];
                g[u].pop_back();
                st.push(v);
            }
            else{
                path.push_back(u);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());

        return path;
    }
};
