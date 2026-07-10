class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int mx = INT_MAX;
        int mn = -mx;
        while(x){
            int rem = x % 10;
            x /= 10;

            if((res > mx / 10) or (res == mx / 10 and rem > mx % 10)) return 0;
            if((res < mn / 10) or (res == mn / 10 and rem < mn % 10)) return 0;
            res = (res * 10) + rem;
        }
        return res;
    }
};
