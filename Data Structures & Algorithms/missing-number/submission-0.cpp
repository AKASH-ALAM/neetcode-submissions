class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        n = (n * (n + 1)) / 2LL;
        for(auto &it : nums) n -= it;
        return n;
    }
};
