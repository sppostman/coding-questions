class Solution {
public:
    int merge(vector<int>&nums, vector<int>&temp, int l, int mid, int r){
        if(l==r)
            return 0;
        int i=l, j=mid;
        int count = 0;

        for(i=l; i<mid; i++){
            while(j<=r && nums[i] > 2LL * (long)nums[j])
                j++;
            count += (j-(mid));
        }

        i=l,j=mid;
        int k=l;
        while(i<mid && j<=r){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while(i < mid)
            temp[k++] = nums[i++];
        while(j <= r)
            temp[k++] = nums[j++];
        for(i=l; i<=r; i++)
            nums[i] = temp[i];
        return count;
    }
    int mergeSort(vector<int>& nums, vector<int>&temp, int l, int r){
        if(l>=r)
            return 0;
        int count=0;
        int mid = (l+r)/2;
        // printf("Mergesort %d...%d...%d (%d...%d...%d)\n",l,mid,r,nums[l],nums[mid],nums[r]);
        count += mergeSort(nums,temp,l,mid);
        count += mergeSort(nums,temp,mid+1,r);
        count += merge(nums,temp,l,mid+1,r);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size()-1);
    }
};