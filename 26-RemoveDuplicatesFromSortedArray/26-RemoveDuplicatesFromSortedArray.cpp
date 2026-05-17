// Last updated: 5/17/2026, 5:52:43 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int q = 1, p = 0;
        if(n==1) return 1;
        if(n==2){
            if(nums[p] == nums[q]){
                return 1;
            }
            else
                return 2;
        }
        while(q<n){
            if (nums[p] == nums[q]) {
                q++;
            } 
            else{
                break;
            }
        }
        while(q<n){
            if(nums[p]!=nums[q]){
                p++;
                nums[p]=nums[q];
                q++;
            }
            else{
                q++;
            }
        }
        return p+1;
    }
};