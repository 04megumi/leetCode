/*
    time limit: O(log(m+n))
    
----------------------------------------------------------------
    firstly, there're two pointers: p1, p2.                    
----------------------------------------------------------------
                       a1[1,2,3,4,5]    a2[3,4,5,6]
    consider  (1) odd  meidian is 5th, {p1,p2}={2,1},{3,0}
                       ==> when odd, p1+p2 = (l1+l2+1)/2 - 2;

                  test a1[1,2,3,4,5]    a2[1,2]
                  ==> p1+p2 = 2
                  actually, {p1,p2}={1,1}

                  and midian = max=max(nums[p1], nums[p2])

                    
                        a1[1,2] a2[3,4]
              (2) even  median is 2nd,3rd {p1,p2}={1,0}
                        ==> when even p1+p2 = (l1+l2)/2 - 1;

                  test a1[1,3,5,7] a2[2,4,6,8]
                  ==> p1+p2=3
                  actually, {p1,p2}=[2,1]
------------------------------------------------------------------
     conclusion: (1) p1+p2 = (l1+l2)/2 - 1(no matter odd or even)
                 (2) midian = max(nums1[p1],nums2[p2]) (odd)
                              (nums1[p1]+nums2[p2])/2 (even)
------------------------------------------------------------------
     solution: let p1 binary_search and p2=f(p1),
               until ..
------------------------------------------------------------------
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int p1 = 0, p2 = 0, key = (nums1.size()+nums2.size())/2 - 1;
        int left = 0, right = nums1.size()-1;
        if(key<0) return nums1[0];
        if() return (nums1.size()+nums2.size())%2 ? nums1[key-nums1.size()+1] : (nums1[key-nums1.size()+1]+nums2[key-nums1.size()+])*1.0/2;
        while(left<=right){
            p1 = (right+left) >> 1;
            p2 = key - p1;
            if(p1==nums1.size()-1) break;
            if(p2<0) {right=p1-1; continue;}
            if(max(nums1[p1], nums2[p2])<min(nums1[p1+1],nums2[p2+1])) break;
            if(nums1[p1]>nums2[p2+1]) right=p1-1;
            if(nums2[p2]>nums1[p1+1]) left=p1+1;
        }
        return (nums1.size()+nums2.size())%2 ? max(nums1[p1],nums2[p2]) : (nums1[p1]+nums2[p2])*1.0/2;
    }
};
