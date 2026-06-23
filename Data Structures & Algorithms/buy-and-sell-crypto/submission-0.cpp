class Solution {
public:
    int maxProfit(vector<int>& v) {
        int len = v.size();
        vector <int> mn(len), mx(len);
        int Min = v[0], Max = v[len-1];
        for(int i = 0; i < len; i++) {
            Min = min(Min, v[i]);
            mn[i] = Min;
        }
        for(int i = len-1; i >= 0; i--){
            Max = max(Max, v[i]);
            mx[i] = Max;
        }
        int ans = 0;
        for(int i = 0; i < len; i++) ans = max(ans, mx[i]-mn[i]);
        return ans;
    }
};
