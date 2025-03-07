/*
    f(l,r) = min(l,r) * (r-l)
    suppose l < r, then f(l,r-1) < f(l,r)
            r > l, then f(l+1,r) < f(l,r)
            r = l, then f(l+1,r), f(l,r-1) < f(l,r)
    证明: max f(i,j) (i!=j) 不存在于 f(l,l+1),...f(l,r)
    因为: f(l,l+1),...f(l,r) <= f(l,r) <= f(l+1,r) <= max f(i,j)
    r = l max next就可以
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, ans = 0;

        while(l<r) {
            ans = max(ans,(r-l)*min(height[l],height[r]));
            bool is = height[l]<=height[r];
            l += is ? 1 : 0;
            r -= is ? 0 : 1;
        }

        return ans;
    }
};

int main() {
    
    std::vector<int> v = {1,8,6,2,5,4,8,3,7};
    Solution s;
    std::cout<<s.maxArea(v)<<std::endl;

    return 0;
}
