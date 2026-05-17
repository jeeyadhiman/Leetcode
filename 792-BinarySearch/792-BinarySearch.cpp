// Last updated: 5/17/2026, 5:51:39 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                high=mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return -1;
    }
};