class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0, i = 0, j = i, left = 0;
        vector <int> index(256, -1);
        while(i <= j and j < (int) s.size()){
            if(index[(int)s[j]] == -1) index[(int)s[j]] = j;
            else {
                mx = max(mx, j-i);
                left = index[(int)s[j]] + 1;
                while(i < left) index[(int)s[i++]] = -1;
                index[(int)s[j]] = j;
            }
            cout << i << ' ' << j << endl;
            mx = max(mx, j-i + 1);
            j++;
        }
        return mx;
    }
};
