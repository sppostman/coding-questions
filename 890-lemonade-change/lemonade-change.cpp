class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> galla;

        for(int b : bills){
            galla[b]++;

            if(b > 5){
                if(b==20){
                    if(galla[10]>0)
                        galla[10]--;
                    else
                        galla[5] -= 2;
                }
                galla[5]--;
                if(galla[5] < 0 || galla[10] < 0)
                    return false;
            }
        }
        return true;
    }
};