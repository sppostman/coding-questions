class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int targetCount = n/3 + 1;

        int c1=0,c2=0;
        int el1=-1, el2=-1;
        for(int n:nums){
            if(n == el1)    
                c1++;
            else if(n==el2)
                c2++;
            else if(c1 == 0 && n != el2){
                c1=1;
                el1=n;
            }
            else if(c2 == 0 && n != el1){
                c2=1;
                el2=n;
            }
            else if(n != el1){
                c1--;
                c2--;
            }
        }
        // printf("el1 -- %d,   el2 -- %d \n", el1,el2);
        c1=0,c2=0;
        vector<int> res;
        for(int n:nums){
            if(n==el1){
                c1++;
                if(c1 == targetCount)
                    res.push_back(el1);
                if(res.size() == 2)
                    break;
            }
            else if(n==el2){
                c2++;
                if(c2 == targetCount)
                    res.push_back(el2);
                if(res.size() == 2)
                    break;
            }
        }
        return res;
        

        // Map - O(n) space & time
        // unordered_map<int,int> counter;
        // vector<int> res;
        // for(int n:nums){
        //     counter[n]++;
        //     if(counter[n] == targetCount){
        //         res.push_back(n);
        //     }
        // }
        // return res;
    }
};