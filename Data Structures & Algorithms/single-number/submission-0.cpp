class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arrayXor = 0;
        for(int i=0;i<nums.size();i++){
            arrayXor^=nums[i];
        }
        return arrayXor;
    }
};
