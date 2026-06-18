class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> triplets;
        set<set<int>> st;
        set <vector<int>> v;

        for(int i = 0; i < (int) nums.size(); i++){
            for(int j = i + 1; j < (int) nums.size(); j++){
                int val = nums[i] + nums[j];
                auto it = lower_bound(nums.begin(), nums.end(), -val);
                if(it != nums.end()){
                    int k = it - nums.begin();
                    if(i != k and j != k and val + nums[k] == 0) {
                        set <int> tmp;
                        tmp.insert(i); tmp.insert(j); tmp.insert(k);
                        st.insert(tmp);
                    }
                }
            }
        }

        for(auto tmp : st){
            vector <int> val;
            for(auto it : tmp) val.push_back(nums[it]);
            v.insert(val);
        }
        for(auto tmp : v) triplets.push_back(tmp);
        return triplets;
    }
};
