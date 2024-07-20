class Solution {
public:
    bool canPlace(vector<int>& position, int m, int force){
        int currPlaced = position[0];
        int placed = 1;

        for(int i=1; i<position.size(); i++){
            int pos = position[i];
            if(pos-currPlaced >= force){
                currPlaced = pos;
                placed++;
                if(placed == m)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position[0];

        while(l<=r){
            int mid = l+(r-l)/2;
            if(canPlace(position, m, mid)){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return r;
    }
};