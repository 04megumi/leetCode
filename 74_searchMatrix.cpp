class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()*matrix[0].size()-1;
        while(l<=r) {
            int m = (l+r) >> 1;
            int t = matrix[m/matrix[0].size()][m%matrix[0].size()];
            if(t==target) return true;
            if(t>target) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return false;
    }
};