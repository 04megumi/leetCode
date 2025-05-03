class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) return findMedianSortedArrays(nums2, nums1);
        if(!nums1.size() && nums2.size()==1) return nums2[0];
        int sum = (nums1.size()+nums2.size())%2 ? (nums1.size()+nums2.size()+1)>>1 : (nums1.size()+nums2.size())>>1;
        int l=1,r=nums1.size(),p1=0,p2 =0,t1=0,t2=0;
        while(l<=r) {
            p1 = (l+r)>>1, p2 = sum - p1;
            if(p2>0 && p2>nums2.size()) {
                l = p1+1;
                continue;
            }
            if(p2<0) {
                r=p1-1;
                continue;
            }
            t1 = max(!p1?INT_MIN:nums1[p1-1],!p2?INT_MIN:nums2[p2-1]);
            t2 = min(p1==nums1.size()?INT_MAX:nums1[p1],p2==nums2.size()?INT_MAX:nums2[p2]);
            if(t1<=t2) break;
            if(p2==0||nums1[p1-1]>t2) {
                r = p1-1;
            } else {
                l = p1+1;
            }
        }
        return (nums1.size()+nums2.size())%2 ? t1 : (t1+t2)*1.0/2;
    }
};