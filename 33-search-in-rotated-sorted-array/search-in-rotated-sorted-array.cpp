class Solution {
public:
    int search(vector<int>& arr, int x) {
        int l = 0, r = arr.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(arr[mid] == x)   
                return mid;
            if(
                (arr[l]<=arr[mid] && arr[l] <= x && x <= arr[mid]) ||
                (arr[l]>arr[mid] && (x <= arr[mid] || x>= arr[l]))
            )
                r = mid-1;
            else
                l = mid+1;
        }
        
        return -1;
    }
};