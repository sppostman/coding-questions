class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        map<int, int> positionsInNums2;
        for(int i=0; i<n2; i++)
            positionsInNums2[nums2[i]] = i;
        
        vector<int> nge(n2, -1);
        stack<int> dec;

        for(int i=n2-1; i>=0; i--){
            while(dec.size() && dec.top() <= nums2[i]){
                dec.pop();
            }
            nge[i] = dec.size() ? dec.top() : -1;
            dec.push(nums2[i]);
        }

        vector<int> ngeResult;
        for(int num : nums1){
            ngeResult.push_back(nge[positionsInNums2[num]]);
        }
        return ngeResult;
    }
};