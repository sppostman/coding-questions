class Solution {
public:
    bool checkValidString(string s) {
        int mn=0, mx=0;
        for(char c : s){
            switch(c){
                case '(':
                    mn++;
                    mx++;
                    break;
                case ')':
                    mx--;
                    mn--;
                    break;
                case '*':
                    mn--;
                    mx++;
                    break;
            }
            if(mn < 0)
                mn=0;
            if(mx<0)
                return false;
        }
        return mn==0;
    }
};