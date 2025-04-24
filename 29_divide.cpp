#include <iostream>
using namespace std;

#define INT_MIN -2147483648
#define INT_MAX 2147483647

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(divisor==1) return dividend;
        if(divisor==-1) return dividend==INT_MIN?INT_MAX:-dividend;

        bool isMinus = dividend>0 != divisor>0;
        if(dividend>0) dividend = -dividend;
        if(divisor>0) divisor = -divisor;

        int ans = 0;
        while(dividend<=divisor) {
            int ts = 1, td = divisor;
            while(td>= INT_MIN/2-1 && td<<1 >= dividend) {
                td = td<<1;
                ts = ts<<1;
            }
            dividend -= td;
            ans += ts;
        }

        return isMinus ? -ans : ans;
    }
};


int main() {
    Solution s;
    cout << s.divide(-2147483648, 2) << endl;
}
