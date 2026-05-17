// Last updated: 5/17/2026, 5:51:53 PM
class Solution {
public:
    int totalf(vector<int> nums,int n){
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        return total;
    }
    int findmin(vector<int> nums,int n){
        int mini=nums[0];
        for(int i=1;i<n;i++){
            mini=max(mini,nums[i]);
        }
        return mini;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans;
        int low=findmin(nums,n);
        int high=totalf(nums,n);
        while(low<=high){
            int count=1,sum=0;
            int mid=(low+high)/2;
            for(int i=0;i<n;i++){
                if(sum+nums[i]<=mid){
                    sum+=nums[i];
                }
                else{
                    count++;
                    sum=nums[i];
                }
            }
            if(count<=k){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};