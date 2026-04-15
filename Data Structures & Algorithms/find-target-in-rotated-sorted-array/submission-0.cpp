class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo+ (hi-lo)/2;
            if(nums[mid]==target)return mid;
            else{
                if(nums[mid]<nums[0]){
                    if(nums[mid]<target){
                        if(target<=nums.back())lo=mid+1;
                        else hi=mid-1;
                    }else{
                        hi = mid-1;
                    }
                }else{
                    if(nums[mid]<target){
                        lo = mid+1;
                    }else{
                        if(target>=nums[0])hi=mid-1;
                        else lo=mid+1;
                    }
                }
            }
        }
        return -1;
    }
};
