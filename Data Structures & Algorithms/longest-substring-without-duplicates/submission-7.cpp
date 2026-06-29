class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0, left = 0;
        vector <int> index(256, -1);
        for(int i = 0; i < (int) s.size(); i++){
            auto idx = s[i];
            if(index[idx] >= left) left = index[idx] + 1;
            index[idx] = i;
            mx = max(mx, i - left + 1);
        }
        return mx;
    }
};