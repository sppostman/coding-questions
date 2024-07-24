class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        int i = 0, j = 0;
        int taken = 0;
        int goal = (n+1)/2;
        int goal2 = n%2 == 0 ? goal+1 : goal;
        int el1, el2;

        while(taken < goal2){
            taken++;
            int picked;
            if(i<n1 && j<n2){
                if(nums1[i] <= nums2[j]){
                    picked = nums1[i];
                    i++;
                } else {
                    picked = nums2[j];
                    j++;
                }
            } else {
                picked = i<n1 ? nums1[i++] : nums2[j++];
            }
            if(taken == goal || taken == goal2)
                cout<<picked<<endl;
            if(taken == goal)
                el1 = el2 = picked;
            if(taken == goal2)
                el2 = picked;
        }

        return (el1+el2)*1.0/2;
    }
};