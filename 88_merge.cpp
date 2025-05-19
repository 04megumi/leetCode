class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t(m+n, 0);
        int i=0, j=0;
        while(i!=m||j!=n) {
            if(j==n||i!=m&&nums1[i]<=nums2[j]) {
                t[i+j] = nums1[i];
                i++;
            } else {
                t[i+j] = nums2[j];
                j++;
            }
        }
        for(int i=0;i<m+n;i++) nums1[i]=t[i];
    }
};