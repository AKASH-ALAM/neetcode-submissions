class Solution {
public:
    int maxProfit(vector<int>& v) {
        int mx = 0, mn = v[0];
        for(int i = 0; i < (int) v.size(); i++){
            mx = max(mx, v[i] - mn);
            mn = min(mn, v[i]);
        }
        return mx;
    }
};
