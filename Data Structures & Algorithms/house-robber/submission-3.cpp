class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int a = nums[0], b = max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            int curr = max(b,a+nums[i]);
            a = b;
            b = curr;
        }
        return b;
    }
};
