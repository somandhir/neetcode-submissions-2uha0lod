class Solution {
public:
    int findMin(vector<int> &nums) {
        // [5,6,1,2,3,4]
        int lo = 0;
        int hi = nums.size()-1;
        int ans = nums[0];
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]<nums[0]){
                ans = min(ans,nums[mid]);
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
