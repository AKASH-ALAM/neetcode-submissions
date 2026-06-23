class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0, right = h.size() - 1;
        int left_max = 0, right_max = 0;
        int sum = 0;

        while (left < right) {
            if (h[left] < h[right]) {
                if (h[left] >= left_max) left_max = h[left];
                else sum += left_max - h[left];
                left++;
            } else {
                if (h[right] >= right_max) right_max = h[right];
                else sum += right_max - h[right];
                right--;
            }
        }
        return sum;
    }
};
