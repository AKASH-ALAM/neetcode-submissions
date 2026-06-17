class Solution {
public:
    bool isAnagram(string s, string t) {
        if((int) s.size() != (int) t.size()) return false;
        map <char, int> ss, tt;
        for(int i = 0; i < (int) s.size(); i++) ss[s[i]]++;
        for(int i = 0; i < (int) t.size(); i++) tt[t[i]]++;
    
        for(int i = 0; i < (int) s.size(); i++) {
            if(ss[s[i]] != tt[s[i]]) return false;
        }

        return true;
    }
};
