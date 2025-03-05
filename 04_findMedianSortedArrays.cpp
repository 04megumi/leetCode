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
     case: [1,4,5,6,7] [1,2]
           [3,4,5,6,7] [1,2]
           [1,2,3,4] [-4,-3,-2,-1]
           [1,2,3,4] [-1,1]
           [1,2] [1]
           [1,2] [3]
           [1,2,3] [5.6]
           [3,3] [1,2]

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) 
            return findMedianSortedArrays(nums2,nums1);
        
        int add = nums1.size()+nums2.size();
        int n1 = nums1.size(), n2 = nums2.size();
        
        if(!n2 && add==1)
            return nums1[0];

        if(!n2 && add!=1)
            return add%2 ? nums1[add>>1] : (nums1[add>>1]+nums1[add/2-1])*1.0/2;

        if(n1==1 && n2==1)
            return (nums1[0]+nums2[0])*1.0/2;

        if(nums2[n2-1]<=nums1[add>>1-n2+1])
            return add%2 ? max(nums1[add/2-n2],nums2[n2-1]):(nums1[add/2-n2]+(n1==n2?nums2[n2-1]:max(nums2[n2-1],nums1[add/2-n2-1]))*1.0/2);

        if(nums1[add>>1-1]<=nums2[0])
            return add%2 ? min(nums2[0],nums1[add>>1]):(nums1[add/2-1]+(n1==n2?nums2[0]:min(nums1[add>>1],nums2[0])))*1.0/2;


        return 0;
    }
};


int main()
{   
    vector<int> nums1 = {3,3};
    vector<int> nums2 = {1,2};
    
    cout << "nums1:";
    for(int i=0;i<nums1.size();i++) cout << nums1[i] << " ";
    cout << endl;
    cout << "nums2:";
    for(int i=0;i<nums2.size();i++) cout << nums2[i] << " ";
    cout << endl;

    Solution s;
    cout << "median:" << s.findMedianSortedArrays(nums1,nums2) << endl;

    return 0;
}
