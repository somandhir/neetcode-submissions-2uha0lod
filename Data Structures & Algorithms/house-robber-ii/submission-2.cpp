class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        // case 1 -> robs 1st house
        int a = nums[0], b = nums[0];
        for(int i=2;i<n-1;i++){
            int curr = max(a+nums[i],b);
            a = b;
            b = curr;
        }
        int res1 = b;
        a = 0;
        b = nums[1];
        for(int i=2;i<n;i++){
            int curr = max(a+nums[i],b);
            a = b;
            b = curr;

        }
        return max(res1,b);
    }
};
