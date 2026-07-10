class Solution {
public:
    int reverse(int x) {
        int res = 0, mx = INT_MAX;
        cout << mx << endl;
        vector <int> v(11), vv(11);
        int i = 9, cnt = 0;
        while(mx){
            v[i] = mx % 10;
            mx /= 10;
            i--;
        } 
        i = 0;
        while(x){
            vv[i] = abs(x % 10);
            res = (res * 10) + (x % 10);
            x /= 10;
            cnt++;
            i++;
        }
        if(cnt == 10){
            for(int j = 0; j < 10; j++){
                if(vv[j] < v[j]) break;
                if(vv[j] == v[j]) continue;
                if(vv[j] > v[j]) return 0;
            }
        }
        cout << cnt << endl;
        for(auto it : v) cout << it << ' ';
        cout << endl;
        for(auto it : vv) cout << it << ' ';
        return res;
    }
};
