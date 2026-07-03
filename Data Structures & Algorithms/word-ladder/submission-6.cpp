#include <bits/stdc++.h>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> have(wordList.begin(), wordList.end());
        queue <string> q;
        q.push(beginWord);
        int step = 1;

        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                string u = q.front();   q.pop();
                if(u == endWord) return step;

                for(int pos = 0; pos < (int) u.size(); pos++){
                    char tmp = u[pos];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(tmp == ch) continue;
                        u[pos] = ch;
                        if(have.count(u)){
                            q.push(u);
                            have.erase(u);
                        }
                    }
                    u[pos] = tmp;
                }
            }
            step++;
        }
       return 0;
    }
};
