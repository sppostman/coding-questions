class Solution {
public:
    int kthGrammar(int n, int k) {
        // 0
        // 01
        // 0110
        // 0110 1001
        // 01101001 10010110
        // 0110100110010110 1001011001101001
        // printf("Do kth(%d, %d)\n",n,k);
        if(n==1)    return 0;

        int level = pow(2, n-1);
        int mid = level/2;
        if(k <= mid){
            return kthGrammar(n-1, k);
        } else {
            int prev = kthGrammar(n-1, k-mid);
            return !prev;
        }
    }
};