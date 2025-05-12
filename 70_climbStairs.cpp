class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int back2=1, back1=2;
        for(int i=3;i<=n;i++) {
            back1 += back2;
            back2 = back1-back2;
        }
        return back1;
    }
};