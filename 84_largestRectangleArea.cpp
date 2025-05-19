class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size()), right(heights.size(),heights.size()), s(heights.size());
        int ans = INT_MIN, p = 0;
        for(int i=0;i<heights.size();i++) {
            while(p>0&&heights[s[p-1]]>=heights[i]) right[s[--p]] = i;
            left[i] = p<1?-1:s[p-1], s[p++] = i;
        }
        for(int i=0;i<heights.size();i++) ans = max(ans,heights[i]*(right[i]-left[i]-1));
        return ans;
    }
};