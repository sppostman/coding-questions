class Solution {
public: 
    bool search(vector<int>& arr, int x) {
        int l = 0, r = arr.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;
    
            if(arr[mid] == x)   
                return true;

            if(arr[r] == arr[l] && arr[mid] == arr[r])
                l++, r--;
            else if(
                (arr[l]<=arr[mid] && arr[l] <= x && x <= arr[mid]) ||
                (arr[l]>arr[mid] && (x <= arr[mid] || x>= arr[l]))
            )
                r = mid-1;
            else
                l = mid+1;
        }
        
        return false;
    }

    bool searchMore(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid;
        
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[l] && nums[mid] == nums[r])
                l++, r--;
            else if(nums[l] <= nums[mid]){
                if(target < nums[mid] && target >= nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            } else {
                if(target > nums[mid] && target <= nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        
        return false;
    }

    bool binarySearch(vector<int>& nums, int target, int l, int r){
        bool asc = nums[l] <= nums[r];
        // cout << "Searching betn "<<l<<", "<<r<<endl;
        int midIdx;
        while(l <= r){
            midIdx = l+(r-l)/2;
            if(nums[midIdx] == target){
                // cout << "Found at " << midIdx<<endl;                
                return true;
            }
            if(asc){
                if(nums[midIdx] > target)
                    r = midIdx-1;
                else
                    l = midIdx+1;
            } else {
                if(nums[midIdx] > target)
                    l = midIdx+1;
                else
                    r = midIdx-1;
            }
        }
        // cout << "Found nothing" <<endl;
        return false;
    }
    bool searchWeird(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int midIdx;
        
        while(l<r){
            midIdx = l+(r-l)/2;
            // cout << "l: "<<l<<", m: "<<midIdx<<", r: "<<r<<endl;
            
            // Handle duplicates
            if(nums[midIdx] == nums[l] && nums[midIdx] == nums[r]){
                // Check if l is pivot
                if(nums[l] > nums[l+1]){
                    if(target <= nums[l] && target >= nums[0])
                        return binarySearch(nums,target,0,l);
                    return binarySearch(nums,target,l+1,nums.size()-1);
                }
                // Check if r is pivot
                if(nums[r-1] > nums[r]){
                    if(target <= nums[r-1] && target >= nums[0])
                        return binarySearch(nums,target,0,r-1);
                    return binarySearch(nums,target,r,nums.size()-1);
                }
                // If none of l/r is pivot, ignore l,r right away
                l++;
                r--;
            }
            
            // Found pivot
            else if(midIdx+1<nums.size() && nums[midIdx] > nums[midIdx+1]){
                cout << "Searching abruptly"<<endl;
                if(target <= nums[midIdx] && target >= nums[0])
                    return binarySearch(nums,target,0,midIdx);
                return binarySearch(nums,target,midIdx+1,nums.size()-1);
            }
            // Found pivot
            else if(midIdx-1 > -1 && nums[midIdx-1] > nums[midIdx]){
                cout << "Searching abruptly2"<<endl;
                if(target <= nums[midIdx-1] && target >= nums[0])
                    return binarySearch(nums,target,0,midIdx-1);
                return binarySearch(nums,target,midIdx,nums.size()-1);
            }
            
            else if(nums[l] > nums[midIdx])
                r = midIdx-1;
            else
                l = midIdx+1;
        }
        if(nums[0]<=nums[nums.size()-1])
            return binarySearch(nums,target,0,nums.size()-1);
        return binarySearch(nums,target,0,nums.size()-1);
    }
};