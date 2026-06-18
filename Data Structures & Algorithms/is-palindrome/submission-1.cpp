class Solution {
public:
    bool isPalindrome(string s) {
        string ss;   int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] >= 'A' and s[i] <= 'Z') ss += s[i] - 'A' + 'a';
            else if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= '0' and s[i] <= '9')) ss += s[i];
        }
        int l = 0, r = ss.size() - 1;
        while(l < r){
            if(ss[l] != ss[r]) return false;
            l++, r--;
        }
        return true;
    }
};
