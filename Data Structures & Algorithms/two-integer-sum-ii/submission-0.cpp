class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        int a = 0, b = 0;
        while(i < j){
            if(numbers[i] + numbers[j] == target) {
                a = i;
                b = j;
                break;
            }
            else if(numbers[i] + numbers[j] > target) j--;
            else i++;
        }
        return {a+1, b+1};
    }
};
