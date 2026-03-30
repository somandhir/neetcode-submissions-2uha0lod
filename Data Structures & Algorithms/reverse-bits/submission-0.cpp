class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                num|=(1<<(32-i-1));
            }
        }
        return num;
    }
};
