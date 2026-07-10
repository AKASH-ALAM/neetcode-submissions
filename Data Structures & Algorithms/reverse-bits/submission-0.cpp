class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        int j = 31;
        for(int i = 0; i <= 31; i++){
            if(n & (1LL << i)) m |= (1LL << j);
            j--;
        }
        return m;
    }
};
