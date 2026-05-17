// Last updated: 5/17/2026, 5:51:54 PM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j;
        if (n==1) return ;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                nums[i]=0;
                j++;
            }
        }
    }
};