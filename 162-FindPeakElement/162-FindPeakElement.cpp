// Last updated: 5/17/2026, 5:52:07 PM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n-2,mid;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>nums[mid+1] && nums[mid-1]<nums[mid]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid+1]>nums[mid]){
                low=mid+1;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid+1]<nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};