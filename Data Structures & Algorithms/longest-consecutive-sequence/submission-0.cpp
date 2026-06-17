class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int, int> mp;
        int mx = 0;
        for(auto &val : nums) mp[val] = 1;
        vector <int> seq_start;
        for(auto &[val, cnt] : mp){
            if(mp.find(val-1) == mp.end()) seq_start.push_back(val);
        }
        for(auto &val : seq_start){
            int cnt = 1;
            while(mp.find(val + 1) != mp.end()){
                cnt++;
                val++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
