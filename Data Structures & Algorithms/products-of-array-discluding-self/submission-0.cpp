class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector <int> a(len+1), b(len+1);
        a[0] = nums[0], b[len-1] = nums[len-1];

        for(int i = 1; i < (int) nums.size(); i++) {
            a[i] = a[i-1] * nums[i];
        }
        for(int i = len-2; i >= 0; i--){
            b[i] = b[i+1] * nums[i];
        }
        vector <int> ans;
        for(int i = 0; i < len; i++){
            if(i == 0) ans.push_back(b[i+1]);
            else if(i == len-1) ans.push_back(a[i-1]);
            else ans.push_back(a[i-1] * b[i+1]);
        }
        return ans;
    }
};
