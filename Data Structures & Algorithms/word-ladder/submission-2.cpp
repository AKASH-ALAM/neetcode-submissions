#include <bits/stdc++.h>

class Solution {
public:
    unordered_map <string, bool> mp;
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto s : wordList) mp[s] = 1;
        mp[beginWord] = 1;

        int n = (int) wordList.size();
        unordered_map <string, vector<string>> g;
        wordList.push_back(beginWord);

        for(auto v : wordList){
            string u = v;
            for(int i = 0; i < (int) v.size(); i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(v[i] == ch) continue;
                    char tmp = v[i];
                    v[i] = ch;
                    if(mp[v]) g[u].push_back(v);
                    v[i] = tmp;
                }
            }
        }

        unordered_map <string, bool> vis;
        queue <pair<string, int>> q;
        q.push({beginWord, 1});
        vis[beginWord] = 0;

        while(!q.empty()){
            auto [u, cnt] = q.front();
            q.pop();
            if(u == endWord) return cnt;
            for(auto v : g[u]){
                if(!vis[v]) {
                    q.push({v, cnt + 1});
                    vis[v] = 1;
                }
            }
        }
       return 0;
    }
};
