class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {
        // Time O(n)    Space O(n)
        int n = a.size();
        // return count;

        // O(4n) ie. 2xO(2n)   Space O(1)
        return numSubarraysWithLessThanEqSum(a, k) - numSubarraysWithLessThanEqSum(a, k-1);
    }
    int numSubarraysWithLessThanEqSum(vector<int>& a, int k){
        if(k<0)
            return 0;

        int n = a.size();
        
        int i=0, j=0;
        int sum = 0;
        int count = 0;

        while(j<n){
            sum += a[j];
            while(sum > k){
                sum -= a[i];
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};