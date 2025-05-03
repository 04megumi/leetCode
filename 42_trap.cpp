class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> dp1(height.size());
        vector<int> dp2(height.size());
        int ans = 0;
        for(int i=1;i<height.size();i++) {
            dp1[i] = max(height[i-1],dp1[i-1]);
            dp2[height.size()-i-1] = max(height[height.size()-i],dp2[height.size()-i]);
        }
        for(int i=1;i<height.size()-1;i++) {
            int sum = min(dp1[i],dp2[i])-height[i];
            if(sum>0) ans += sum;
        }
        return ans;
    }
};