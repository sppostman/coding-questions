class Solution {
public:
    int minBitFlips(int start, int goal) {
        // return __builtin_popcount(start ^ goal);

        int flipNum = start ^ goal;
        int flipBits = 0;
        while(flipNum>0){
            flipNum = flipNum & (flipNum-1);
            flipBits++;
        }
        return flipBits;
    }
};