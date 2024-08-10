class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n2 < n1)
            return findMedianSortedArrays(nums2, nums1);

        int n = n1+n2;
        int half = (n1+n2+1)/2;

        int l = 0, r = n1;

        while(l<=r){
            int m1 = l+(r-l)/2;
            int m2 = half-m1;
            int bl1 = m1>0 ? nums1[m1-1] : INT_MIN;
            int br1 = m1<n1 ? nums1[m1] : INT_MAX;
            int bl2 = m2>0 ? nums2[m2-1] : INT_MIN;
            int br2 = m2<n2 ? nums2[m2] : INT_MAX;
            if(bl1 <= br2 && bl2 <= br1){
                if(n%2 == 0)
                    return (max(bl1, bl2) + min(br1, br2)*1.0)/2;
                return max(bl1, bl2);
            }
            if(bl1 > br2)
                r = m1-1;
            else
                l = m1+1;
        }
        return -1;

        // int i = 0, j = 0;
        // int taken = 0;
        // int goal = (n+1)/2;
        // int goal2 = n%2 == 0 ? goal+1 : goal;
        // int el1, el2;

        // while(taken < goal2){
        //     taken++;
        //     int picked;
        //     if(i<n1 && j<n2){
        //         if(nums1[i] <= nums2[j]){
        //             picked = nums1[i];
        //             i++;
        //         } else {
        //             picked = nums2[j];
        //             j++;
        //         }
        //     } else {
        //         picked = i<n1 ? nums1[i++] : nums2[j++];
        //     }
        //     if(taken == goal || taken == goal2)
        //         cout<<picked<<endl;
        //     if(taken == goal)
        //         el1 = el2 = picked;
        //     if(taken == goal2)
        //         el2 = picked;
        // }

        // return (el1+el2)*1.0/2;
    }
};