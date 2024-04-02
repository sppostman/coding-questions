class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> nge(n, -1);
        stack<int> gt;
        unordered_map<int,int> pos;
        for(int i=n-1; i>=0; i--){
            int el = nums2[i];
            pos[el] = i;
            while(gt.size() && gt.top()<el)
                gt.pop();
            if(gt.size())
                nge[i] = gt.top();
            gt.push(el);
        }

        vector<int> res(m, -1);
        for(int i=0; i<m; i++){
            int el = nums1[i];
            if(pos.find(el) != pos.end()){
                res[i] = nge[pos[el]];
            }
        }
        return res;
    }
};