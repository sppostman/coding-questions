class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        stack<int> gt;

        for(int i=2*n-1; i>=0; i--){
            int el = nums[i%n];

            while(gt.size() && gt.top() <= el){
                gt.pop();
            }

            if(i<n && gt.size()){
                res[i] = gt.top();
                // cout<< res[i] <<", ";
            }
            
            gt.push(el);
        }

        // 1  2   1    1    2   1
        //        2(0) 2(1) -1 -1 
        return res;
    }
};