class Solution {
private:
    int sum(int a, int b){
        int cr = 0, sum = 0;

        for(int i = 0; i < 31; i++){
            if((a & (1 << i)) and (b & (1 << i))) {
                if(cr == 1) sum |= (1 << i);
                cr = 1;
            }
            else if((a & (1 << i)) or (b & (1 << i))){
                if(cr == 0) sum |= (1 << i);
            }
            else{
                if(cr == 1) {
                    sum |= (1 << i);
                    cr= 0;
                }
            }
        }

        return sum;
    }

    int sub(int a, int b){
        int tmp_a = abs(a), tmp_b = abs(b);
        bool neg = 0;
        if(a < 0 and tmp_a > tmp_b) neg = 1;
        else if(b < 0 and tmp_b > tmp_a) neg = 1;

        if(tmp_a < tmp_b) swap(tmp_a, tmp_b);

        int res = 0, cr = 0;

        for(int i = 0; i < 31; i++){
            if((tmp_a & (1 << i)) == 0 and (tmp_b & (1 << i))) {
                if(cr == 0) {
                    res |= (1 << i);
                }
                cr = 1;
            }
            else if((tmp_a & (1 << i)) and (tmp_b & (1 << i)) == 0){
                if(cr == 0) {
                    res  |= (1 << i);
                } else cr = 0;
            }
            else{
                if(cr == 1){
                    res |= (1 << i);
                }
            }
        }
        if(neg) res = -res;
        return res;
    }
public:
    int getSum(int a, int b) {
        if(a > 0 and b > 0) return sum(a, b);
        else if(a < 0 and b < 0) return -sum(abs(a), abs(b));
        else return sub(a, b);
    }
};
