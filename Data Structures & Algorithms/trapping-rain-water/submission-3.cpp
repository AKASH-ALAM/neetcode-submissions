class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size() < 3) return 0;

        int left = 0, l_val = 0, len = h.size(), right = len - 1, r_val = 0;

        while(left < len and h[left] >= l_val) l_val = h[left++];
        while(right >= 0 and h[right] >= r_val) r_val = h[right--];

        vector <int> v;
        for(int i = left-1; i <= right+1; i++) v.push_back(h[i]);

        for(auto it : v) cout << it << ' ';
        cout << endl;

        int len2 = v.size();
        vector <int> lr(len2), rl(len2);
        stack <int> st, st2;


        for(int i = len2-1; i >= 0; i--){
            while(!st.empty() and v[i] > v[st.top()]) st.pop();
            if(st.empty()) lr[i] = -1;
            else lr[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < len2; i++){
            while(!st2.empty() and v[i] > v[st2.top()]) st2.pop();
            if(st2.empty()) rl[i] = -1;
            else rl[i] = st2.top();
            st2.push(i);
        }
        int sum = 0;
        for(int i = 0; i < len2; i++){
            if(lr[i] == -1) continue;
            sum += (lr[i] - i - 1) * v[i]; 
            for(int j = i + 1; j < lr[i]; j++) sum -= v[j];
            i = lr[i]-1;
        }

        for(int i = len2-1; i >= 0; i--){
            int x = rl[i];
            if(x == -1 or lr[x] != -1) continue;
            sum += (i - x - 1) * v[i];
            for(int j = i-1; j > x; j--) sum -= v[j];
            i = x + 1;
        }

        return sum;
    }
};
