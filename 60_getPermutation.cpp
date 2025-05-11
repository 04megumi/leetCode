class Solution {
public:
    string getPermutation(int n, int k) {
        int c = 1; string ans; k--;
        for(int i=n-1;i>=1;i--) c*=i;
        vector<bool> used(n);
        for(int i=1;i<=n;i++) {
            int t = k/c;
            for(int j=0;j<n;j++) {
                if(!used[j]) {
                    if(!t) {
                        ans+= (j+1+'0');
                        used[j] = true;
                        break;
                    }
                    t--;
                }
            }
            k %= c;
            if(n-i) c /= n-i;
        }
        return ans;
    }
};