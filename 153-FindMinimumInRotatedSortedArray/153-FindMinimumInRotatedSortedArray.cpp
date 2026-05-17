// Last updated: 5/17/2026, 5:52:08 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,n=nums.size();
        int high= n-1;
        int mid,min1=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
        
            if(nums[mid]>= nums[low]){
                min1=min(min1,nums[low]);
                low=mid+1;

            }
            else {
                min1=min(min1,nums[mid]);
                high=mid-1;

            }
        }
        return min1;
    }
};