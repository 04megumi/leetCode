class Solution {
public:
    int reverse(int x) {
        const int upper = 2147483647;
        int ans = 0;
        bool isMinus = x<0;
        // 处理-max
        if(x==-upper-1) return 0;
        x = isMinus ? -x : x;

        while(x) {
            // 处理反转后溢出
            if(ans > upper/10) return 0;
            ans *= 10;
            if(ans/10 == upper/10 && x%10 > (isMinus?8:7)) return 0;
            ans += x%10;
            x /= 10;
        }

        return isMinus ? -ans : ans;
    }
};
