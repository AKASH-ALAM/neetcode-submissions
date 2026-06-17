class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <pair<string, string>> v(strs.size());
        for(int i = 0; i < (int) strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            v[i] = {strs[i], s};
        }
        vector <vector<string>> ans;
        multimap <string, string> mp;
        for(int i = 0; i < (int) v.size(); i++){
            mp.insert({v[i].second, v[i].first});
        }

        vector <pair<string, string>> vv;
        for(auto [a, b] : mp) {
            // cerr << a << ' ' << b << endl;
            vv.push_back({a, b});
        }
        
        if (vv.empty()) return ans;
        ans.push_back({});
        int j = 0;
        for(int i = 0; i < (int) vv.size(); i++){
            if(i > 0 && vv[i].first != vv[i-1].first) {
                ans.push_back({});
                j++;
            }
            ans[j].push_back(vv[i].second);
        }

        return ans;
    }
};
