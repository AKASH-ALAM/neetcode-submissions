class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int, int>> v(nums.size());
        for(int i = 0; i < (int) nums.size(); i++){
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());
        int i = 0, j = (int) nums.size()-1;
        int a = 0, b = 0;
        while(i < j){
            if(v[i].first + v[j].first == target) {
                a = v[i].second;
                b = v[j].second;
                break;
            }
            else if(v[i].first + v[j].first > target) j--;
            else i++;
        }
        if(a < b) return {a, b};
        else return {b, a};
    }
};
