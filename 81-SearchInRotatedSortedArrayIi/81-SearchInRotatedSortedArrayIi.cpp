// Last updated: 5/17/2026, 5:52:31 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high= n-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            
            if(nums[mid]== target){
                return true;
            }
             if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            else if(nums[mid]<=nums[high]){
                if(nums[mid]<= target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high= mid-1;
                }
            }
            else {
                if(nums[low] <= target && target <= nums[mid]){
                    high= mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return false;
    }
};