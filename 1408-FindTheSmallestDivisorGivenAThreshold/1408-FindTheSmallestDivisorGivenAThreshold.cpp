// Last updated: 5/17/2026, 5:51:30 PM
class Solution {
public:
int findmax(vector<int> bloomDay,int n){
        int max1=bloomDay[0];
        for(int i=1;i<n;i++){
            max1=max(max1,bloomDay[i]);
        }
        return max1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=findmax(nums,n);
        int mid,ans;
        int result;
        while(low<=high){
            result=0;
            mid=(low+high)/2;
            for(int i=0;i<n;i++){
                result = result+ceil((double)nums[i] / (double)mid);
            }
            if(result<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};