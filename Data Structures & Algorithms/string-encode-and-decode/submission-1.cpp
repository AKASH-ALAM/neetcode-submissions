class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto &it : strs){
            s += it;
            s += '.';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector <string> ans;
        string ss = "";
        for(int i = 0; i < (int) s.size(); i++){
            if(s[i] == '.'){
                ans.push_back(ss);
                ss = "";
            } else ss += s[i];
        }
        return ans;
    }
};
