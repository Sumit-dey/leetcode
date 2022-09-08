// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++)
            nums1.push_back(nums2[i]);

        double ans;
        sort(nums1.begin(),nums1.end());

        if(nums1.size()%2==1)
            ans=nums1[(nums1.size()/2)];
          else
              ans=(nums1[(nums1.size()/2)-1]+nums1[(nums1.size()/2)])/2.0;

        return ans;
    }
};
