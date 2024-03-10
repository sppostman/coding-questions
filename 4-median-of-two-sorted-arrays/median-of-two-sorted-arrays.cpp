class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int total = nums1.size() + nums2.size();
        int half = (total+1)>>1;
        
        int l=0, r=min(half, n1);
        while(l<=r){
            int el1 = l + ((r-l)>>1);
            int el2 = half-el1;

            int l1 = el1 > 0 ? nums1[el1-1] : -1e7;
            int l2 = el2 > 0 ? nums2[el2-1] : -1e7;
            int r1 = el1 < n1 ? nums1[el1] : 1e7;
            int r2 = el2 < n2 ? nums2[el2] : 1e7;

            printf("l1 %d, r1 %d    l2 %d, r2 %d\n",l1,r1,l2,r2);

            if(l1<=r2 && l2<=r1)
                return (total&1) == 1 ? max(l1, l2) : (max(l1,l2)+min(r1,r2))/2.0;

            if(l1>r2)
                r = el1-1;
            else
                l = el1+1;
        }
        return 0;
    }
};