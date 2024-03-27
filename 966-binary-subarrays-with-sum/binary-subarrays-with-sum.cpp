class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {
        // int n = a.size();
        // vector<int> ps(k+n+1,0); // Better than map, since we know upper limit of sum
        // int sum = 0;
        // int count = 0;
        // for(int i=0; i<n; i++){
        //     sum += a[i];
        //     if(sum == k)
        //         count++;
        //     if(sum-k >= 0)
        //         count+=ps[sum-k];
        //     ps[sum]++;
        // }
        // return count;
        cout<<numSubarraysWithLessThanEqSum(a,k)<<", "<<numSubarraysWithLessThanEqSum(a,k-1)<<endl;
        return numSubarraysWithLessThanEqSum(a, k) - numSubarraysWithLessThanEqSum(a, k-1);
    }
    int numSubarraysWithLessThanEqSum(vector<int>& a, int k){
        int n = a.size();
        if(k<0) return 0;

        int i=0, j=0;
        int count=0, sum=0;
        while(j<n){
            sum += a[j];
            while(i<=j && sum > k)
                sum -= a[i++];
            
            count += j-i+1;
            j++;
        }
        return count;
    }
};